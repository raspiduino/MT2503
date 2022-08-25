#########################################################################
# MTK Resource Generation System
# Module:      resgen_offline_param
# Description: Provide unified log interface for mtk resource generation 
#              system
#########################################################################

import sys
import os
import traceback
import shutil
import time
#import threading
import thread


####################################################
# Resgen Log APIs
####################################################
class ResgenLog:

    @staticmethod
    def d(tag, message):
        ResgenLog.log('[D]', tag, message)

    @staticmethod
    def v(tag, message):
        ResgenLog.log('[V]', tag, message)

    @staticmethod
    def w(tag, message):
        ResgenLog.log('[W]', tag, message)
        
    @staticmethod
    def e(tag, message):
        ResgenLog.log('[E]', tag, 'Error!! ' + message)

    @staticmethod
    def getTimeStampeMark():
        return time.strftime('[%H:%M:%S]', time.localtime())

    @staticmethod
    def log(debugLevelMark, tag, message):
        print(debugLevelMark + ResgenLog.getTimeStampeMark() + ResgenLog.getThreadMark() + '[PY:'+ tag + ']'+ message)

    @staticmethod
    def getThreadMark():
    #   Since thread class is deplicated from python 2.7, if we change the runtime form 2.5/2.6 to 2.7,
    #   the implementation should changed to the following one
    #       threadId = 0
    #       threadObj = threading.currentThread()
    #       if not threadObj is None:
    #           theadId = threadObj.ident
    #       return '[' + str(threadId) + ']'
        return '[TID:' + str(thread.get_ident()) + ']'

