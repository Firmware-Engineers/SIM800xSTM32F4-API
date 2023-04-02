/**
 ******************************************************************************
 * @file            SIM800x_Types.h
 * @author          Maxime  
 * @brief           header file for SIM800 series Modem API common types definitions
 * @brief           This file provides macros and custom type definitions common
 *                  to all SIM800 series.
 * 
 * 
 * @note            History:
 *                   - Feb 17, 2023: Initial release
 * 
 * @note            It has been successfully tested with:
 *                  - IDE:
 *                      * STMCube IDE V1.11.0
 *                  - Toolchain:
 *                      * GNU Tools for STM32 V10.3
 *                  - DTE Devices:
 *                      * STM32F407
 *                  - DCE Devices:
 *                      * SIM800L
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */
 
#ifndef __SIM800X_TYPES_H
#define	__SIM800X_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/**
  * @brief  API status type definition
  */ 
typedef enum
{
    //---------
	SIM800X_OK        			= 0,                                        	//!< Operation completed or done successfully
	SIM800X_ERROR    			= 1,                                        	//!< Error occured
	SIM800X_CME_ERROR           = 2,                                        	//!< CME ERROR, check error response code for more details
	SIM800X_CMS_ERROR           = 3,                                         	//!< CMS ERROR, check error response code for more details
	SIM800X_BR_ERROR            = 4,                                           	//!< Baud rate error
	SIM800X_TIME_OUT            = 5,                                   	        //!< Time-out occurred during operation, no response received
	SIM800X_READY               = 6,                                            //!< System ready
	SIM800X_BUSY                = 7,                   	                        //!< System busy
	SIM800X_INVALID_RESPONSE    = 8                                             //!< No response or invalid response
    //---------        
}SIM800x_APIStatusType;
//-----------------------------------

//-----------------------------------
/** @defgroup API_BAUDRATE_CONSTANTS API supported baud rates type definition 
 * @{
 *  
 */
#define BR_AUTO_BAUDING                     0                                   //!< Auto bauding 
#define BR_1200                             1200                                //!< 1200 bps
#define BR_2400                             2400                                //!< 2400 bps
#define BR_4800                             4800                                //!< 4800 bps
#define BR_9600                             9600                                //!< 9600 bps
#define BR_19200                            19200                               //!< 19200 bps
#define BR_38400                            38400                               //!< 38400 bps                   
#define BR_57600                            57600                               //!< 57600 bps
#define BR_115200                           115200                              //!< 115200 bps
#define BR_230400                           230400                              //!< 230400 bps, not supported for auto-bauding
#define BR_460800                           460800                              //!< 460800 bps, not supported for auto-bauding
/**
  * @}
  */
//-----------------------------------

//-----------------------------------
/** @defgroup API_HTTP_RESPONSE_CODES_CONSTANTS HTTP(S) responses code constants: HTTP 1.1(RFC 2616) 
 * @{
 *  
 */
#define HTTP_CONTINUE                       100                                 //!< Continue
#define HTTP_SWITCH_PROTOCOLS               101                                 //!< Switching Protocols
#define HTTP_OK                             200                                 //!< OK
#define HTTP_CREATED                        201                                 //!< CREATED
#define HTTP_ACCEPTED                       201                                 //!< ACCEPTED 
#define HTTP_NON_AUTH_INFO                  203                                 //!< Non-Authoritative information 
#define HTTP_NO_CONTENT                     204                                 //!< No content
#define HTTP_RST_CONTENT                    205                                 //!< Reset content
#define HTTP_PARTIAL_CONTENT                206                                 //!< Partial Content
#define HTTP_MUL_CHOICES                    300                                 //!< Multiple Choices
#define HTTP_MOVED_PERM                     301                                 //!< Moved Permanently
#define HTTP_FOUND                          302                                 //!< Found
#define HTTP_SEE_OTHER                      303                                 //!< See Other
#define HTTP_NOT_MODIFIED                   304                                 //!< Not Modified
#define HTTP_USE_PROXY                      305                                 //!< Use Proxy
#define HTTP_TEMP_REDIRECT                  307                                 //!< Temporary Redirect
#define HTTP_BAD_REQUEST                    400                                 //!< Bad request
#define HTTP_UNAUTHORIZED                   401                                 //!< Unauthorized
#define HTTP_PAYMENT_REQUIRED               402                                 //!< Payment required
#define HTTP_FORBIDDEN                      403                                 //!< Forbidden
#define HTTP_NOT_FOUND                      404                                 //!< Not found
#define HTTP_METHOD_NOT_ALLOWED             405                                 //!< Method not allowed
#define HTTP_NOT_ACCEPTABLE                 406                                 //!< Not acceptable
#define HTTP_PROXY_AUTH_REQUIRED            407                                 //!< Proxy Authentication Required
#define HTTP_REQ_TIME_OUT                   408                                 //!< Request Timeout 
#define HTTP_CONFLICT                       409                                 //!< Conflict
#define HTTP_GONE                           410                                 //!< Gone
#define HTTP_LENGTH_REQUIRED                411                                 //!< Length Required
#define HTTP_PRE_COND_FAILED                412                                 //!< Precondition Failed
#define HTTP_REQ_ENT_TOO_LARGE              413                                 //!< Request Entity Too Large
#define HTTP_REQ_URI_TOO_LARGE              414                                 //!< Request-URI Too Large
#define HTTP_UNSUPPORTED_MEDIA_TYPE         415                                 //!< Unsupported Media Type 
#define HTTP_REQ_RANGE_NOT_SATISFIABLE      416                                 //!< Requested range not satisfiable
#define HTTP_EXPECTATION_FAILED             417                                 //!< Expectation Failed
#define HTTP_INT_SERVER_ERROR               500                                 //!< Internal Server Error
#define HTTP_NOT_IMPLEMENTED                501                                 //!< Not implemented
#define HTTP_BAD_GATEWAY                    502                                 //!< Bad gateway
#define HTTP_SERVICE_UNAVAILABLE            503                                 //!< Service unavailable
#define HTTP_GATEWAY_TIME_OUT               504                                 //!< Gateway time-out
#define HTTP_HTTP_VER_NOT_SUPPORTED         505                                 //!< HTTP version not supported
#define HTTP_NOT_HTTP_PDU                   600                                 //!< Not HTTP PDU
#define HTTP_NETWORK_ERROR                  601                                 //!< Network error
#define HTTP_NO_MEMORY                      602                                 //!< No memory
#define HTTP_DNS_ERROR                      603                                 //!< DNS error
#define HTTP_STACK_BUSY                     604                                 //!< Stack busy    
/**
  * @}
  */
//-----------------------------------

//-----------------------------------
/** @defgroup API_SIM800X_CME_ERROR_CONSTANTS SIM800x CME ERROR codes constants 
 * @{
 *  
 */
#define CME_PHONE_FAILURE                   0                                   //!< Phone failure
#define CME_NO_CON_TO_PHONE                 1                                   //!< No connection to phone
#define CME_PHONE_ADPT_LINK_RESERVED        2                                   //!< Phone-adaptor link reserved
#define CME_OP_NOT_ALLOWED                  3                                   //!< Operation not allowed
#define CME_OP_NOT_SUPPORTED                4                                   //!< Operation not supported
#define CME_PH_SIM_PIN_REQUIRED             5                                   //!< PH-SIM PIN required
#define CME_PH_FSIM_PIN_REQUIRED            6                                   //!< PH-FSIM PIN required                   
#define CME_PH_FSIM_PUK_REQUIRED            7                                   //!< PH-FSIM PUK required
#define CME_SIM_NOT_INSERTED                10                                  //!< SIM not inserted
#define CME_SIM_PIN_REQUIRED                11                                  //!< SIM PIN required
#define CME_SIM_PUK_REQUIRED                12                                  //!< SIM PUK required
#define CME_SIM_FAILURE                     13                                  //!< SIM failure
#define CME_SIM_BUSY                        14                                  //!< SIM busy
#define CME_SIM_WRONG                       15                                  //!< SIM wrong
#define CME_INCORRECT_PASSWORD              16                                  //!< Incorrect password
#define CME_SIM_PIN2_REQUIRED               17                                  //!< SIM PIN2 required
#define CME_SIM_PUK2_REQUIRED               18                                  //!< SIM PUK2 required
#define CME_MEM_FULL                        20                                  //!< Memory full
#define CME_INV_INDEX                       21                                  //!< Invalid index
#define CME_NOT_FOUND                       22                                  //!< Not found
#define CME_MEM_FAILURE                     23                                  //!< Memory failure
#define CME_TXT_STR_TOO_LONG                24                                  //!< Text string too long
#define CME_INV_CHR_IN_TXT_STRING           25                                  //!< Invalid characters in text string
#define CME_DIAL_STR_TOO_LONG               26                                  //!< Dial string too long
#define CME_INV_CHAR_IN_DIAL_STRING         27                                  //!< Invalid characters in dial string
#define CME_NO_NET_SERVICE                  30                                  //!< No network service
#define CME_NET_TIMEOUT                     31                                  //!< Network timeout
#define CME_NET_NOT_ALLOWED                 32                                  //!< Network not allowed - emergency call only
#define CME_NET_PERS_PIN_REQUIRED           40                                  //!< Network personalisation PIN required
#define CME_NET_PERS_PUK_REQUIRED           41                                  //!< Network personalisation PUK required
#define CME_NET_SUBSET_PERS_PIN_REQUIRED    42                                  //!< Network subset personalisation PIN required
#define CME_NET_SUBSET_PERS_PUK_REQUIRED    43                                  //!< Network subset personalisation PUK required
#define CME_SERV_PROV_PERS_PIN_REQUIRED     44                                  //!< Service provider personalisation PIN required
#define CME_SERV_PROV_PERS_PUK_REQUIRED     45                                  //!< Service provider personalisation PUK required
#define CME_CORP_PERS_PIN_REQUIRED          46                                  //!< Corporate personalisation PIN required
#define CME_CORP_PERS_PUK_REQUIRED          47                                  //!< Corporate personalisation PUK required
#define CME_RESOURCE_LIMITATION             99                                  //!< Resource limitation
#define CME_UNKWOWN1                        100                                 //!< Unknown
#define CME_ILLEGAL_MS                      103                                 //!< Illegal MS
#define CME_ILLEGAL_ME                      106                                 //!< Illegal ME
#define CME_GPRS_SERV_NOT_ALLOWED           107                                 //!< GPRS services not allowed
#define CME_PLMN_NOT_ALLOWED                111                                 //!< PLMN not allowed
#define CME_LOC_AREA_NOT_ALLOWED            112                                 //!< Location area not allowed
#define CME_ROAMING_NOT_ALLOWED             113                                 //!< Roaming not allowed in this location area
#define CME_SERV_OPTION_NOT_SUPPORTED       132                                 //!< Service option not supported
#define CME_REQ_SERV_OPTION_NOT_SUBSCRIBED  133                                 //!< Requested service option not subscribed
#define CME_SERV_OPTION_TEMP_OUT_OF_ORDER   134                                 //!< Service option temporarily out of order
#define CME_UNSPECIFIED_GPRS_ERROR          148                                 //!< Unspecified GPRS error
#define CME_PDP_AUTH_FAILURE                149                                 //!< PDP authentication failure
#define CME_INV_MOBILE_CLASS                150                                 //!< Invalid mobile class
#define CME_DNS_RESOLVE_FAILED              160                                 //!< DNS resolve failed
#define CME_SOCKET_OPEN_FAILED              161                                 //!< Socket open failed
#define CME_MMS_TASK_IS_BUSY_NOW            171                                 //!< MMS task is busy now
#define CME_MMS_DATA_IS_OVERSIZE            172                                 //!< The MMS data is oversize
#define CME_OP_IS_OVERTIME                  173                                 //!< The operation is overtime
#define CME_NO_MMS_RECEIVER                 174                                 //!< There is no MMS receiver
#define CME_STOR_FOR_ADDR_IS_FULL           175                                 //!< The storage for address is full
#define CME_NOT_FIND_THE_ADDRESS            176                                 //!< Not find the address
#define CME_CON_TO_NET_IS_FAILED            177                                 //!< The connection to network is failed
#define CME_FAILED_TO_READ_PUSH_MESSAGE     178                                 //!< Failed to read push message
#define CME_NOT_PUSH_MESSAGE                179                                 //!< This is not a push message
#define CME_GPRS_NOT_ATTACHED               180                                 //!< GPRS is not attached
#define CME_TCPIP_STACK_BUSY                181                                 //!< TCPIP stack is busy
#define CME_MMS_STOR_IS_FULL                182                                 //!< The MMS storage is full
#define CME_BOX_IS_EMPTY                    183                                 //!< The box is empty
#define CME_FAILED_TO_SAVE_MMS              184                                 //!< Failed to save MMS
#define CME_IT_IS_IN_EDIT_MODE              185                                 //!< It is in edit mode
#define CME_IT_IS_NOT_IN_EDIT_MODE          186                                 //!< It is not in edit mode
#define CME_NO_CONTENT_IN_BUFFER            187                                 //!< No content in the buffer
#define CME_NOT_FIND_THE_FILE               188                                 //!< Not find the file
#define CME_FAILED_TO_RECEIVE_MMS           189                                 //!< Failed to receive MMS
#define CME_FAILED_TO_READ_MMS              190                                 //!< Failed to read MMS
#define CME_NOT_MNOTIFICATION_IND           191                                 //!< Not M-Notification.ind
#define CME_MMS_INCLOSURE_IS_FULL           192                                 //!< The MMS inclosure is full
#define CME_UNKNOWN2                        193                                 //!< Unknown
#define CME_NO_ERROR                        600                                 //!< No Error
#define CME_UNRECOGNIZED_COMMAND            601                                 //!< Unrecognized Command
#define CME_RETURN_VALUE_ERROR              602                                 //!< Return Value Error
#define CME_SYNTAX_ERROR                    603                                 //!< Syntax Error
#define CME_UNSPECIFIED_ERROR               604                                 //!< Unspecified Error
#define CME_DATA_TRANSFER_ALREADY           605                                 //!< Data Transfer Already
#define CME_ACTION_ALREADY                  606                                 //!< Action Already
#define CME_NOT_AT_COMMAND                  607                                 //!< Not At Cmd
#define CME_MULTI_CMD_TOO_LONG              608                                 //!< Multi Cmd too long
#define CME_ABORT_COPS                      609                                 //!< Abort Cops
#define CME_NO_CALL_DISC                    610                                 //!< No Call Disc
#define CME_BT_SAP_UNDEFINED                611                                 //!< BT SAP Undefined
#define CME_BT_SAP_NOT_ACCESSIBLE           612                                 //!< BT SAP Not Accessible
#define CME_BT_CARD_REMOVED                 613                                 //!< BT SAP Card Removed
#define CME_AT_NOT_ALLOWED_BY_CUSTOMER      614                                 //!< AT Not Allowed By Customer
#define CME_MISS_REQ_CMD_PARAMETER          753                                 //!< Missing required cmd parameter
#define CME_INV_SIM_COMMAND                 754                                 //!< Invalid SIM command
#define CME_INV_FILE_ID                     755                                 //!< Invalid File Id
#define CME_MISS_REQ_P123_PARAMETER         756                                 //!< Missing required P1/2/3 parameter
#define CME_INV_P123_PARAMETER              757                                 //!< Invalid P1/2/3 parameter
#define CME_MISS_REQ_CMD_DATA               758                                 //!< Missing required command data
#define CME_INV_CHAR_IN_CMD_DATA            759                                 //!< Invalid characters in command data
#define CME_INV_INPUT_VALUE                 765                                 //!< Invalid input value
#define CME_UNSUPPORTED_MODE                766                                 //!< Unsupported mode
#define CME_OPERATION_FAILED                767                                 //!< Operation failed
#define CME_MUX_ALREADY_RUNNING             768                                 //!< Mux already running
#define CME_UNABLE_TO_GET_CONTROL           769                                 //!< Unable to get control
#define CME_SIM_NETWORK_REJECT              770                                 //!< SIM network reject
#define CME_CALL_SETUP_IN_PROGRESS          771                                 //!< Call setup in progress
#define CME_SIM_POWERED_DOWN                772                                 //!< SIM powered down
#define CME_SIM_FILE_NOT_PRESENT            773                                 //!< SIM file not present
#define CME_PARAM_COUNT_NOT_ENOUGH          791                                 //!< Param count not enough
#define CME_PARAM_COUNT_BEYOND              792                                 //!< Param count beyond
#define CME_PARAM_VAL_RANGE_BEYONG          793                                 //!< Param value range beyond
#define CME_PARAM_TYPE_NOT_MATCH            794                                 //!< Param type not match
#define CME_PARAM_FORMAT_INVALID            795                                 //!< Param format invalid
#define CME_GET_NULL_PARAM                  796                                 //!< Get a null param
#define CME_CFUN_STATE_IS_0_4               797                                 //!< CFUN state is 0 or 4
/**
  * @}
  */
//-----------------------------------

//-----------------------------------
/** @defgroup API_SIM800X_CMS_ERROR_CONSTANTS SIM800x CMS ERROR codes constants 
 * @{
 *  
 */
#define CMS_UNASSIGNED                      1                                   //!< Unassigned(unallocated) number
#define CMS_NO_ROUTE_TO_DESTINATION         3                                   //!< No route to destination
#define CMS_CH_UNACCEPTABLE                 6                                   //!< Channel unacceptable 
#define CMS_OP_DETERM_BARRING               8                                   //!< Operator determined barring
#define CMS_CALL_BARRED                     10                                  //!< Call barred
#define CMS_RESERVED                        11                                  //!< Reserved
#define CMS_NORM_CALL_CLEARING              16                                  //!< Normal call clearing                   
#define CMS_USER_BUSY                       17                                  //!< User busy
#define CMS_NO_USER_RESPONDING              18                                  //!< No user responding
#define CMS_USER_ALERT_NO_ANSWER            19                                  //!< User alerting, no answer
#define CMS_SM_TR_REJECTED                  21                                  //!< Short message transfer rejected
#define CMS_NUM_CHANGED                     22                                  //!< Number changed
#define CMS_PRE_EMPTION                     25                                  //!< Pre-emption
#define CMS_NOT_SELECT_USER_CLEARING        26                                  //!< Non-selected user clearing
#define CMS_DEST_OUT_OF_SERVICE             27                                  //!< Destination out of service
#define CMS_INV_NUM_FORMAT                  28                                  //!< Invalid number format (incomplete number)
#define CMS_FAC_REJECTED                    29                                  //!< Facility rejected
#define CMS_RESP_TO_STAT_ENQUIRY            30                                  //!< Response to STATUS ENQUIRY
#define CMS_NORM_UNSPECIFIED                32                                  //!< Normal, unspecified
#define CMS_NO_CIRCUIT_CH_AVAILABLE         34                                  //!< No circuit/channel available
#define CMS_NET_OUT_OF_ORDER                38                                  //!< Network out of order
#define CMS_TEMP_FAILURE                    41                                  //!< Temporary failure
#define CMS_SWITCH_EQUIP_CONGESTION         42                                  //!< Switching equipment Congestion
#define CMS_ACCESS_INFO_DISCARDED           43                                  //!< Access information discarded
#define CMS_REQ_CIRCUIT_CH_NOT_AVAILABLE    44                                  //!< Requested circuit/channel not available
#define CMS_RES_UNAVAILAIBLE_UNSPECIFIED    47                                  //!< Resources unavailable, unspecified
#define CMS_QOS_SERV_UNAVAILABLE            49                                  //!< Quality of service unavailable
#define CMS_REQ_FAC_NOT_SUBSCRIBED1         50                                  //!< Requested facility not subscribed
#define CMS_REQ_FAC_NOT_SUBSCRIBED2         55                                  //!< Requested facility not subscribed
#define CMS_BEAR_CAP_NOT_AUTHORIZED         57                                  //!< Bearer capability not authorized
#define CMS_BEAR_CAP_NOT_AVAILABLE          58                                  //!< Bearer capability not presently available
#define CMS_SERV_OPT_NOT_AVAILABLE          63                                  //!< Service or option not available, unspecified
#define CMS_BEAR_SRV_NOT_IMPLEMENTED1       65                                  //!< Bearer service not implemented
#define CMS_ACM_EQ_GR_ACM_MAXIMUM           68                                  //!< ACM equal or greater than ACM maximum
#define CMS_REQ_FAC_NOT_IMPLEMENTED         69                                  //!< Requested facility not implemented
#define CMS_ONLY_REST_DINFO_BEAR_CAP_AVAILABLE  70                              //!< Only restricted digital information bearer capability is available
#define CMS_SERV_OPT_NOT_IMPLEMENTED2       79                                  //!< Service or option not implemented, unspecified
#define CMS_INV_TRAN_ID_VALUE               81                                  //!< Invalid transaction identifier value
#define CMS_USER_NOT_MEM_OF_CUG             87                                  //!< User not member of CUG
#define CMS_INCOMp_DESTINATION              88                                  //!< Incompatible destination
#define CMS_INV_TRAN_NET_SELECTION          91                                  //!< Invalid transit network selection
#define CMS_SEM_INC_MESSAGE                 95                                  //!< Semantically incorrect message
#define CMS_INV_MAND_INFORMATION            96                                  //!< Invalid mandatory information
#define CMS_MSG_TYPE_NON_EXIST_IMPLEMENTED  97                                  //!< Message type non-existent or not implemented
#define CMS_MSG_TYPE_NOT_COMP_PRO_STATE     98                                  //!< Message type not compatible with protocol state
#define CMS_INFO_ELEM_NON_EXIST_IMPLEMENTED 99                                  //!< Information element non-existent or not implemented
#define CMS_COND_INFO_ELT_ERROR             100                                 //!< Conditional information element error
#define CMS_MSG_NOT_COMP_WITH_PROTOCOL      101                                 //!< Message not compatible with protocol
#define CMS_REC_ON_TIMER_EXPIRY             102                                 //!< Recovery on timer expiry
#define CMS_PRO_ERROR_UNSPECIFIED           111                                 //!< Protocol error, unspecified
#define CMS_INTER_UNSPECIFIED               127                                 //!< Interworking, unspecified
#define CMS_TELE_INTER_NOT_SUPPORTED        128                                 //!< Telematic interworking not supported
#define CMS_SM_TYPE0_NOT_SUPPORTED          129                                 //!< Short message Type 0 not supported
#define CMS_CANNOT_REPL_SHORT_MESSAGE       130                                 //!< Cannot replace short message
#define CMS_UNSPECIFIED_TPPID_ERROR         143                                 //!< Unspecified TP-PID error
#define CMS_DATA_CS_NOT_SUPPORTED           144                                 //!< Data coding scheme (alphabet) not supported
#define CMS_MSG_CLASS_NOT_SUPPORTED         145                                 //!< Message class not supported
#define CMS_UNSPECIFIED_TPDCS_ERROR         159                                 //!< Unspecified TP-DCS error
#define CMS_CMD_CANNOT_BE_ACTED             160                                 //!< Command cannot be acted
#define CMS_CMD_UNSUPPORTED                 161                                 //!< Command unsupported
#define CMS_UNSPECIFIED_TP_CMP_ERROR        175                                 //!< Unspecified TP-Command error
#define CMS_TPDU_NOT_SUPPORTED              176                                 //!< TPDU not supported
#define CMS_SC_BUSY                         192                                 //!< SC busy
#define CMS_NO_SC_SUBSCRIPTION              193                                 //!< No SC subscription
#define CMS_SC_SYSEM_FAILURE                194                                 //!< SC system failure
#define CMS_INV_SME_ADDRESS                 195                                 //!< Invalid SME address
#define CMS_DEST_SME_BARRED                 196                                 //!< Destination SME barred
#define CMS_SM_REJECTED_DUPLICATE_SM        197                                 //!< SM Rejected-Duplicate SM
#define CMS_TPVPF_NOT_SUPPORTED             198                                 //!< TP-VPF not supported
#define CMS_TPVP_NOT_SUPPORTED              199                                 //!< TP-VP not supported
#define CMS_SIM_SMS_STOR_FULL               208                                 //!< SIM SMS storage full
#define CMS_NO_SMS_STOR_CAP_IN_SIM          209                                 //!< No SMS storage capability in SIM
#define CMS_ERROR_IN_MS                     210                                 //!< Error in MS
#define CMS_MEM_CAP_EXCEEDED                211                                 //!< Memory Capacity Exceeded
#define CMS_SIM_APP_TK_BUSY                 212                                 //!< SIM Application Toolkit Busy
#define CMS_SIM_DATA_DOWNLOAD_ERROR         213                                 //!< SIM data download error
#define CMS_CP_RETRY_EXCEED                 224                                 //!< CP retry exceed
#define CMS_RP_TRIP_TIMEOUT                 225                                 //!< RP trim timeout
#define CMS_SMS_CON_BROKEN                  226                                 //!< SMS connection broken
#define CMS_UNSPECIFIED_ERROR_CAUSE         255                                 //!< Unspecified error cause
#define CMS_ME_FAILURE                      300                                 //!< ME failure
#define CMS_SMS_RESERVED                    301                                 //!< SMS reserved
#define CMS_OP_NOT_ALLOWED                  302                                 //!< Operation not allowed
#define CMS_OP_NOT_SUPPORTED                303                                 //!< Operation not supported
#define CMS_INV_PDU_MODE                    304                                 //!< Invalid PDU mode
#define CMS_INV_TEXT_MODE                   305                                 //!< Invalid text mode
#define CMS_SIM_NOT_INSERTED                310                                 //!< SIM not inserted
#define CMS_SIM_PIN_NECESSARY               311                                 //!< SIM pin necessary
#define CMS_PH_SIM_PIN_NECESSARY            312                                 //!< PH SIM pin necessary
#define CMS_SIM_FAILURE                     313                                 //!< SIM failure
#define CMS_SIM_BUSY                        314                                 //!< SIM busy
#define CMS_SIM_WRONG                       315                                 //!< SIM wrong
#define CMS_SIM_PUK_REQUIRED                316                                 //!< SIM PUK required
#define CMS_SIM_PIN2_REQUIRED               317                                 //!< SIM PIN2 required
#define CMS_SIM_PUK2_REQUIRED               318                                 //!< SIM PUK2 required
#define CMS_MEM_FAILURE                     320                                 //!< Memory failure
#define CMS_INV_MEM_INDEX                   321                                 //!< Invalid memory index
#define CMS_MEM_FULL                        322                                 //!< Memory full
#define CMS_INV_INPUT_PARAMETER             323                                 //!< Invalid input parameter
#define CMS_INV_INPUT_FORMAT                324                                 //!< Invalid input format
#define CMS_INV_INPUT_VALUE                 325                                 //!< Invalid input value
#define CMS_SMSC_ADDR_UNKNWON               330                                 //!< SMSC address unknown
#define CMS_NO_NETWORK                      331                                 //!< No network
#define CMS_NETWORK_TIMEOUT                 332                                 //!< Network timeout
#define CMS_NOT_CNMA_ACK                    340                                 //!< No cnma ack
#define CMS_UNKNOWN                         500                                 //!< Unknown
#define CMS_SMS_NO_ERROR                    512                                 //!< SMS no error
#define CMS_MSG_LEN_EXEEDS_MAX_LEN          513                                 //!< Message length exceeds maximum length
#define CMS_INV_REQ_PARAMETERS              514                                 //!< Invalid request parameters
#define CMS_ME_STOR_FAILURE                 515                                 //!< ME storage failure
#define CMS_INV_BEAR_SERVICE                516                                 //!< Invalid bearer service
#define CMS_INV_SERV_MODE                   517                                 //!< Invalid service mode
#define CMS_INV_STOR_TYPE                   518                                 //!< Invalid storage type
#define CMS_INV_MSG_FORMAT                  519                                 //!< Invalid message format
#define CMS_TOO_MANY_MO_CONT_MESSAGES       520                                 //!< Too many MO concatenated messages
#define CMS_SMSAL_NOT_READY                 521                                 //!< SMSAL not ready
#define CMS_SMSAL_NO_MORE_SERVICE           522                                 //!< SMSAL no more service
#define CMS_NOT_SUP_TPSTA_REP_TPCMD_IN_STORAGE  523                             //!< Not support TP-Status-Report & TP-Command in storage
#define CMS_RESERVED_MTI                    524                                 //!< Reserved MTI
#define CMS_NO_FREE_ENTITY_IN_RL_LAYER      525                                 //!< No free entity in RL layer
#define CMS_PORT_NUM_IS_ALRDY_REGISTERED    526                                 //!< The port number is already registerred
#define CMS_NO_FREE_ENTITY_PORT_NUMBER      527                                 //!< There is no free entity for port number
#define CMS_MORE_MSG_TO_SEND_STA_ERROR      528                                 //!< More Message to Send state error
#define CMS_MO_SMS_IS_NOT_ALLOW             529                                 //!< MO SMS is not allow
#define CMS_GPRS_IS_SUSPENDED               530                                 //!< GPRS is suspended
#define CMS_ME_STORAGE_FULL                 531                                 //!< ME storage full
#define CMS_DOING_SIM_REFRESH               532                                 //!< Doing SIM refresh
/**
  * @}
  */
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* __SIM800X_TYPES_H */

