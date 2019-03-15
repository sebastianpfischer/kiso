from Configuration import *
from CChannel.CCUart import *
from CChannel.Message import *
from CChannel.TlvTypes import *
from time import sleep
import unittest
import logging
import threading
  
class TestCase_SocketTestSuiteTeardown(unittest.TestCase):

    testCaseId = 8

    def __init__(self, testSection, testSuite):
        super(TestCase_SocketTestSuiteTeardown, self).__init__()
        self.testSection = testSection
        self.testSuite = testSuite
        self.logger = logging.getLogger(__name__)

    def setUp(self):
        pass

    def runTest(self):
        pass

    def tearDown(self):
        print("====================================================")
        print("tearDown: TC_1.8.8-TestCase_SocketTestSuiteTeardown ")
        print("====================================================")

        self.TP1 = self.testSection.getTestParticipantProxy("TP1_COSP")

        self.logger.debug("[TC] TP1 " + str(self.TP1.getName()))

        message = Message(msgType=COMMAND, msgToken=self.testSection.getMsgToken(),    
                          type=TestSuiteTeardown,
                          testSection=self.testSection.getSectionId(),
                          testSuite=self.testSuite.getSuiteId(),
                          testCase=self.testCaseId)

        ack = self.TP1.sendAndWaitForAck(message, 120)
        self.assertEqual(NO_ERROR, ack.getErrorCode(), "we don't expect any error code")

