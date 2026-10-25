#define LOG_CHAT_SYS(LEVEL,MESSAGE) systemChat LOG_SYS_FORMAT(LEVEL,MESSAGE)

#ifdef DEBUG_MODE_FULL
    #define TRACE_0(MESSAGE) LOG_SYS_FILELINENUMBERS('TRACE',str diag_frameNo + ' ' + (MESSAGE))

    #define TRACE_CHAT_0(MESSAGE) LOG_CHAT_SYS('TRACE',str diag_frameNo + ' ' + (MESSAGE))
    #define TRACE_CHAT_1(MESSAGE,A) LOG_CHAT_SYS('TRACE',PFORMAT_1(str diag_frameNo + ' ' + (MESSAGE),A))
    #define TRACE_CHAT_2(MESSAGE,A,B) LOG_CHAT_SYS('TRACE',PFORMAT_2(str diag_frameNo + ' ' + (MESSAGE),A,B))
    #define TRACE_CHAT_3(MESSAGE,A,B,C) LOG_CHAT_SYS('TRACE',PFORMAT_3(str diag_frameNo + ' ' + (MESSAGE),A,B,C))
    #define TRACE_CHAT_4(MESSAGE,A,B,C,D) LOG_CHAT_SYS('TRACE',PFORMAT_4(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D))
    #define TRACE_CHAT_5(MESSAGE,A,B,C,D,E) LOG_CHAT_SYS('TRACE',PFORMAT_5(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D,E))
    #define TRACE_CHAT_6(MESSAGE,A,B,C,D,E,F) LOG_CHAT_SYS('TRACE',PFORMAT_6(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D,E,F))
    #define TRACE_CHAT_7(MESSAGE,A,B,C,D,E,F,G) LOG_CHAT_SYS('TRACE',PFORMAT_7(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D,E,F,G))
    #define TRACE_CHAT_8(MESSAGE,A,B,C,D,E,F,G,H) LOG_CHAT_SYS('TRACE',PFORMAT_8(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D,E,F,G,H))
    #define TRACE_CHAT_9(MESSAGE,A,B,C,D,E,F,G,H,I) LOG_CHAT_SYS('TRACE',PFORMAT_9(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D,E,F,G,H,I))
#else
    #define TRACE_0(MESSAGE) /* disabled */

    #define TRACE_CHAT_0(MESSAGE) /* disabled */
    #define TRACE_CHAT_1(MESSAGE,A) /* disabled */
    #define TRACE_CHAT_2(MESSAGE,A,B) /* disabled */
    #define TRACE_CHAT_3(MESSAGE,A,B,C) /* disabled */
    #define TRACE_CHAT_4(MESSAGE,A,B,C,D) /* disabled */
    #define TRACE_CHAT_5(MESSAGE,A,B,C,D,E) /* disabled */
    #define TRACE_CHAT_6(MESSAGE,A,B,C,D,E,F) /* disabled */
    #define TRACE_CHAT_7(MESSAGE,A,B,C,D,E,F,G) /* disabled */
    #define TRACE_CHAT_8(MESSAGE,A,B,C,D,E,F,G,H) /* disabled */
    #define TRACE_CHAT_9(MESSAGE,A,B,C,D,E,F,G,H,I) /* disabled */
#endif
