from Configuration import *
from CChannel.CCUart import *
from CChannel.Message import *
from CChannel.TlvTypes import *

import unittest
import logging
import time

class TestCase_SocketOpenBeforeConnEvent(unittest.TestCase):

    testCaseId = 9

    def __init__(self, testSection, testSuite):
        super(TestCase_SocketOpenBeforeConnEvent, self).__init__()
        self.testSection = testSection
        self.testSuite = testSuite
        self.logger = logging.getLogger(__name__)

    def setUp(self):
        print("==============================================")
        print("setUp: TC_1.7.9-TestCase_SocketOpenBeforeConnEvent ")
        print("==============================================")

        self.TP1 = self.testSection.getTestParticipantProxy("TP1_COSP")

        self.logger.debug("[TC] TP1 " + str(self.TP1.getName()))

        message = Message(msgType=COMMAND, msgToken=self.testSection.getMsgToken(),
                          type=TestCaseSetup,
                          testSection=self.testSection.getSectionId(),
                          testSuite=self.testSuite.getSuiteId(),
                          testCase=self.testCaseId)

        ack = self.TP1.sendAndWaitForAck(message, 90)
        self.assertEqual(NO_ERROR, ack.getErrorCode(), "we don't expect any error code")

    def runTest(self):
        print("============================================")
        print("Run: TC_1.7.9-TestCase_SocketOpenBeforeConnEvent ")
        print("============================================")
        messageTP1 = Message(msgType=COMMAND, msgToken=self.testSection.getMsgToken(),
                          type=TestCaseRun,
                          testSection=self.testSection.getSectionId(),
                          testSuite=self.testSuite.getSuiteId(),
                          testCase=self.testCaseId)

        self.logger.debug("[TC] sending command to TP1" + str(messageTP1.serialize()))

        ack = self.TP1.sendAndWaitForAck(messageTP1, 60)
        self.assertEqual(NO_ERROR, ack.getErrorCode(), "we don't expect any error code")

        result = self.testSection.waitForReports([self.TP1], 300)

        report1 = self.TP1.getLastReport()

        self.assertEqual(True, result, "the waitForReports has timed out...\n"
                         + "\ntime duration 1:   "  + str(report1))

        self.assertNotEqual(None, report1, "report shouldn't be empty")
        self.assertEqual(NO_ERROR, report1.getErrorCode(), "OK, this is the end of the test case")

    def tearDown(self):
        print("=================================================")
        print("TearDown: TC_1.7.9-TestCase_SocketOpenBeforeConnEvent ")
        print("=================================================")
        message = Message(msgType=COMMAND, msgToken=self.testSection.getMsgToken(),
                          type=TestCaseTeardown,
                          testSection=self.testSection.getSectionId(),
                          testSuite=self.testSuite.getSuiteId(),
                          testCase=self.testCaseId)

        ack = self.TP1.sendAndWaitForAck(message, 60)
        self.assertEqual(NO_ERROR, ack.getErrorCode(), "we don't expect any error code")

