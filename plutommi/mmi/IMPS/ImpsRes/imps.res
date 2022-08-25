#include "mmi_features.h"

#ifdef __MMI_IMPS__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_IMPS">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h"/>

    <!-------------------------------------------- String Resource Area ----------------------------------------------->
    <STRING id="STR_ID_IMPS"/>
    <STRING id="STR_ID_IMPS_USERNAME"/>
    <STRING id="STR_ID_IMPS_AUTO_LOGIN"/>
    <STRING id="STR_ID_IMPS_PROGRESSING"/>
    <STRING id="STR_ID_IMPS_LOGIN"/>
    <STRING id="STR_ID_IMPS_SIGNING_IN"/>
    <STRING id="STR_ID_IMPS_GET_ACCT"/>
    <STRING id="STR_ID_IMPS_USE_EXIST_ACCT"/>
    <STRING id="STR_ID_IMPS_REM_PWD"/>    
    <STRING id="STR_ID_IMPS_SERVER"/>
    <STRING id="STR_ID_IMPS_PROXY_SERVER"/>
    <STRING id="STR_ID_IMPS_PROXY_PORT"/>
    <STRING id="STR_ID_IMPS_LOGOUT"/>
    <STRING id="STR_ID_IMPS_CHAT_ROOMS"/>
    <STRING id="STR_ID_IMPS_CHAT_ROOM"/> 
    <STRING id="STR_ID_IMPS_WRITE_MSG"/>
    <STRING id="STR_ID_IMPS_SEL_FROM_FILE"/>
    <STRING id="STR_ID_IMPS_GET_FILE_SUCC"/>

    <STRING id="STR_ID_IMPS_LOGIN_ESTABLISH_CONN"/>
    <STRING id="STR_ID_IMPS_LOGIN_CONNECTING"/>
    <STRING id="STR_ID_IMPS_LOGIN_AUTH"/>
    <STRING id="STR_ID_IMPS_LOGIN_CONNECTED"/>

#ifdef __MMI_OP11_IMPS__
    /* emoticons */
    <STRING id="STR_ID_IMPS_AND"/>         /* used for emoticons */
    <STRING id="STR_ID_IMPS_SMILE"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_SHOUT"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_WINK"/>        /* do not change the order */  
    <STRING id="STR_ID_IMPS_TONGUE"/>      /* do not change the order */  
    <STRING id="STR_ID_IMPS_SAD"/>         /* do not change the order */  
    <STRING id="STR_ID_IMPS_SUNGLASSES"/>  /* do not change the order */  
    <STRING id="STR_ID_IMPS_LIPS1"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_PUZZLED"/>     /* do not change the order */  

    <STRING id="STR_ID_IMPS_SLEEP"/>       /* do not change the order */    
    <STRING id="STR_ID_IMPS_BIG_GRIN"/>    /* do not change the order */ 
    <STRING id="STR_ID_IMPS_DEVIL"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_TEAR"/>        /* do not change the order */  

    <STRING id="STR_ID_IMPS_SUPERSAD"/>    /* do not change the order */  
    <STRING id="STR_ID_IMPS_BLUSH"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_ANGEL"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_EYEBROW"/>     /* do not change the order */      
    <STRING id="STR_ID_IMPS_EYEROLL"/>     /* do not change the order */  
    <STRING id="STR_ID_IMPS_NERD"/>        /* do not change the order */  
    <STRING id="STR_ID_IMPS_PUKE"/>        /* do not change the order */  
    <STRING id="STR_ID_IMPS_SARCASTIC"/>   /* do not change the order */  
    <STRING id="STR_ID_IMPS_WHEEP"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_ANGRY"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_CAKE"/>        /* do not change the order */  

    <STRING id="STR_ID_IMPS_BEER"/>        /* do not change the order */  
    <STRING id="STR_ID_IMPS_BROKEN_HEART"/>/* do not change the order */  
    <STRING id="STR_ID_IMPS_HEART"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_GIFT"/>        /* do not change the order */  

    <STRING id="STR_ID_IMPS_CAT"/>         /* do not change the order */  
    <STRING id="STR_ID_IMPS_COKTAIL"/>     /* do not change the order */  
    <STRING id="STR_ID_IMPS_TEETH"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_THINKING"/>    /* do not change the order */  
    <STRING id="STR_ID_IMPS_ZIPIT"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_GOSSIP"/>      /* do not change the order */  
    <STRING id="STR_ID_IMPS_PARTY"/>       /* do not change the order */  

    <STRING id="STR_ID_IMPS_DISGUST"/>     /* do not change the order */  
    <STRING id="STR_ID_IMPS_HUG1"/>        /* do not change the order */  
    <STRING id="STR_ID_IMPS_SHEEP"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_HUG2"/>        /* do not change the order */  
    <STRING id="STR_ID_IMPS_THUMB_UP"/>    /* do not change the order */  
    <STRING id="STR_ID_IMPS_COFFEE"/>      /* do not change the order */  
    <STRING id="STR_ID_IMPS_LIPS2"/>       /* do not change the order */  
    <STRING id="STR_ID_IMPS_THUMB_DOWN"/>  /* do not change the order */  
    <STRING id="STR_ID_IMPS_WILTED_ROSE"/> /* do not change the order */  
    <STRING id="STR_ID_IMPS_DOG"/>         /* do not change the order */    
#else /* __MMI_OP11_IMPS__ */
    <STRING id="STR_ID_IMPS_HAPPY"/>       /* do not change the order */ 
    <STRING id="STR_ID_IMPS_SAD"/>         /* do not change the order */
    <STRING id="STR_ID_IMPS_ANGRY"/>       /* do not change the order */
    <STRING id="STR_ID_IMPS_JEALOUS"/>     /* do not change the order */
    <STRING id="STR_ID_IMPS_ASHAMED"/>     /* do not change the order */
    <STRING id="STR_ID_IMPS_INVINCIBLE"/>  /* do not change the order */
    <STRING id="STR_ID_IMPS_IN_LOVE"/>     /* do not change the order */
    <STRING id="STR_ID_IMPS_SLEEPY"/>      /* do not change the order */
    <STRING id="STR_ID_IMPS_BORED"/>       /* do not change the order */
    <STRING id="STR_ID_IMPS_EXCITED"/>     /* do not change the order */
    <STRING id="STR_ID_IMPS_ANXIOUS"/>     /* do not change the order */
#endif /* #ifdef __MMI_OP11_IMPS__ */


    /* pre-defined text */
    <STRING id="STR_ID_IMPS_TEMPLATE_1"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_2"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_3"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_4"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_5"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_6"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_7"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_8"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_9"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_10"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_11"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_12"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_13"/>
    <STRING id="STR_ID_IMPS_TEMPLATE_14"/>

    /* Help */
    <STRING id="STR_ID_IMPS_HELP_LOGIN"/>
    <STRING id="STR_ID_IMPS_HELP_CONTACT_LIST"/>
    <STRING id="STR_ID_IMPS_HELP_CHAT"/>
    <STRING id="STR_ID_IMPS_HELP_ADD_CONTACT"/>

    <STRING id="STR_ID_IMPS_EMPTY_USERNAME"/>
    <STRING id="STR_ID_IMPS_EMPTY_PASSWORD"/>
    <STRING id="STR_ID_IMPS_EMPTY_SERVER"/>
    <STRING id="STR_ID_IMPS_SIZE_TOO_LARGE"/>
    <STRING id="STR_ID_IMPS_INSERT_SYMBOL"/>
    <STRING id="STR_ID_IMPS_TEMPLATE"/>
    <STRING id="STR_ID_IMPS_INVITE"/>
    <STRING id="STR_ID_IMPS_SAVE_TEXT"/>
    <STRING id="STR_ID_IMPS_EMPTY_FILENAME"/>
    <STRING id="STR_ID_IMPS_INVALID_FILENAME"/>
    <STRING id="STR_ID_IMPS_DUPLICATE_FILENAME"/>
    <STRING id="STR_ID_IMPS_FILENAME_TOO_LONG"/>
    <STRING id="STR_ID_IMPS_EMPTY_INPUT"/>
    <STRING id="STR_ID_IMPS_JUMP_TO"/>
    <STRING id="STR_ID_IMPS_OPEN_CHAT_ROOM"/>
    <STRING id="STR_ID_IMPS_NAME"/>
    <STRING id="STR_ID_IMPS_DISPLAY_NAME"/>
    <STRING id="STR_ID_IMPS_WITHDRAW_CONT"/>
    <STRING id="STR_ID_IMPS_WITHDRAW"/>
    <STRING id="STR_ID_IMPS_RECALL_USER"/>
    <STRING id="STR_ID_IMPS_RECALL"/>
    <STRING id="STR_ID_IMPS_RECALL_ASK"/>
    <STRING id="STR_ID_IMPS_OPEN"/>
    <STRING id="STR_ID_IMPS_VIEW_PARTICIPANT"/>
    <STRING id="STR_ID_IMPS_INVITING"/>
    <STRING id="STR_ID_IMPS_INVITE_FAIL"/>
    <STRING id="STR_ID_IMPS_JOINED_ROOM"/>
    <STRING id="STR_ID_IMPS_CONT_LIST"/>
    <STRING id="STR_ID_IMPS_ABOUT_ME"/>
    <STRING id="STR_ID_IMPS_WATCHER_LIST"/>
    <STRING id="STR_ID_IMPS_SEND_READ_MSG"/>
    <STRING id="STR_ID_IMPS_DEL_CONTACT"/>
    <STRING id="STR_ID_IMPS_BLOCK_CONTACT"/>
    <STRING id="STR_ID_IMPS_GRANT_CONTACT"/>
    <STRING id="STR_ID_IMPS_ADD_CONTACT"/>
    <STRING id="STR_ID_IMPS_MANAGE_GROUPS"/>
    <STRING id="STR_ID_IMPS_MY_PROFILE"/>
    <STRING id="STR_ID_IMPS_STATUS"/>
    <STRING id="STR_ID_IMPS_MOOD"/>
    <STRING id="STR_ID_IMPS_MY_PICTURE"/>
    <STRING id="STR_ID_IMPS_SEL_FILE"/>

    /* status str-id, index dependent */
    <STRING id="STR_ID_IMPS_UPDATEING"/>
    <STRING id="STR_ID_IMPS_OFFLINE"/>
    <STRING id="STR_ID_IMPS_ONLINE"/>
    <STRING id="STR_ID_IMPS_BUSY"/>
    <STRING id="STR_ID_IMPS_AWAY"/>
    /* status str-id", index dependent */

    <STRING id="STR_ID_IMPS_SEARCH_CONTACT"/>
    <STRING id="STR_ID_IMPS_SEARCH_RESULT"/>
    <STRING id="STR_ID_IMPS_PHONE_NO"/>
    <STRING id="STR_ID_IMPS_ALIAS"/>
    <STRING id="STR_ID_IMPS_EMAIL"/>
    <STRING id="STR_ID_IMPS_MYSELF"/>
    <STRING id="STR_ID_IMPS_LIST_MEMBER"/>
    <STRING id="STR_ID_IMPS_HIDE"/>
    <STRING id="STR_ID_IMPS_SHOW"/>
    <STRING id="STR_ID_IMPS_LIST_FULL"/>
    <STRING id="STR_ID_IMPS_GROUP_NOT_EMPTY"/>
    <STRING id="STR_ID_IMPS_CONTACT_EXIST"/>
    <STRING id="STR_ID_IMPS_SELECT_GROUP"/>
    <STRING id="STR_ID_IMPS_ANONYMOUS"/>
    <STRING id="STR_ID_IMPS_MSG_CANNOT_SEND"/>
    <STRING id="STR_ID_IMPS_REFRESH"/>
    <STRING id="STR_ID_IMPS_ERR_UNSUPPORT_SERVICE"/>
    <STRING id="STR_ID_IMPS_ERR_NOT_LOGIN"/>
    <STRING id="STR_ID_IMPS_ERR_ALREADY_LOGIN"/>
    <STRING id="STR_ID_IMPS_ERR_NETWORK_BUSY"/>
    <STRING id="STR_ID_IMPS_ERR_CONN_FAILED"/>
    <STRING id="STR_ID_IMPS_ERR_INVALID_PASSWD"/>
    <STRING id="STR_ID_IMPS_ERR_INVALID_USERNAME"/>
    <STRING id="STR_ID_IMPS_ERR_INVALID_SERVER"/>
    <STRING id="STR_ID_IMPS_ERR_ROOM_EXIST"/>
    <STRING id="STR_ID_IMPS_ERR_ROOM_NOT_EXIST"/>
    <STRING id="STR_ID_IMPS_ERR_CHAT_ROOM_FULL"/>
    <STRING id="STR_ID_IMPS_ERR_ABORT_FAIL"/>
    <STRING id="STR_ID_IMPS_ERR_AUTH_FAIL"/>
    <STRING id="STR_ID_IMPS_ERR_REQUEST_TIMEOUT"/>
    <STRING id="STR_ID_IMPS_ERR_MSG_SEND_FAIL"/>
    <STRING id="STR_ID_IMPS_ERR_CONT_FULL"/>
    <STRING id="STR_ID_IMPS_ERR_CONT_LIST_FULL"/>
    <STRING id="STR_ID_IMPS_ERR_SNAME_IN_USE"/>
    <STRING id="STR_ID_IMPS_ERR_ROOM_ALREADY_JOINED"/>
    <STRING id="STR_ID_IMPS_ERR_ROOM_NOT_JOINED"/>
    <STRING id="STR_ID_IMPS_ERR_ROOM_FULL"/>
    <STRING id="STR_ID_IMPS_ERR_NO_SEATCH_RESULT"/>
    <STRING id="STR_ID_IMPS_ERR_INVALID_PORT"/>
    <STRING id="STR_ID_IMPS_ERR_EMPTY_NAME"/>
    <STRING id="STR_ID_IMPS_ERR_EMPTY_DISP_NAME"/>
    <STRING id="STR_ID_IMPS_ERR_EMPTY_ROOM_NAME"/>
    <STRING id="STR_ID_IMPS_ERR_EMPTY_ROOM_ID"/>
    <STRING id="STR_ID_IMPS_NEW_ROOM_CREATED"/>
    <STRING id="STR_ID_IMPS_ERR_NO_SPACE"/>
    <STRING id="STR_ID_IMPS_ERR_NO_GROUP"/>
    <STRING id="STR_ID_IMPS_ERR_UNKNOWN_ERROR"/>
    <STRING id="STR_ID_IMPS_ERR_INVALID_REQUEST"/>
    <STRING id="STR_ID_IMPS_ERR_SERVER_NOT_SUPPORT"/>
    <STRING id="STR_ID_IMPS_ERR_CONT_NOT_SUPPORT"/>
    <STRING id="STR_ID_IMPS_ERR_NOT_GET_ACCEPT_TYPE"/>
    <STRING id="STR_ID_IMPS_ERR_SESSION_PROBLEM"/>
    <STRING id="STR_ID_IMPS_ERR_PRESENCE_PROBLEM"/>
    <STRING id="STR_ID_IMPS_ERR_GROUP_PROBLEM"/>
    <STRING id="STR_ID_IMPS_ERR_SEND_REQUEST_FAIL"/>
    <STRING id="STR_ID_IMPS_ERR_RECV_RESPONSE_FAIL"/>
    <STRING id="STR_ID_IMPS_ERR_TOO_BROAD_SEARCH_CRITERIA"/>
    <STRING id="STR_ID_IMPS_ERR_MSG_REJECT_BY_RECIPIENT"/>
    <STRING id="STR_ID_IMPS_ERR_FILE_ACCESS_ERROR"/>
    <STRING id="STR_ID_IMPS_ERR_CONT_NOT_READY"/>
    <STRING id="STR_ID_IMPS_ERR_CONT_NOT_ALL_SYNC"/>
    <STRING id="STR_ID_IMPS_ERR_SERVER_OR_NETWORK_ERROR"/>
    <STRING id="STR_ID_IMPS_ERR_NO_ENOUGH_SPACE"/>
    <STRING id="STR_ID_IMPS_ERR_NO_AVAILABLE_VERSION"/>
    <STRING id="STR_ID_IMPS_ERR_SYSTEM_MESSAGE_RESPONSE_REQUIRE"/>
    <STRING id="STR_ID_IMPS_ERR_TOO_MANY_WRONG_SM_RESPONSE"/>
    <STRING id="STR_ID_IMPS_ERR_UNKNOWN_SYSTEM_MESSAGE_ID"/>
    <STRING id="STR_ID_IMPS_ERR_INCORRECT_VERIFICATION_KEY"/>
    <STRING id="STR_ID_IMPS_ERR_MESSAGE_TOO_LARGE"/>
    <STRING id="STR_ID_IMPS_ERR_DATA_NOT_COMPLETE"/>
    <STRING id="STR_ID_IMPS_ERR_ID_TOO_LONG"/>
    <STRING id="STR_ID_IMPS_ERR_PSW_TOO_LONG"/>
    <STRING id="STR_ID_IMPS_ERR_NEED_NORAML_LOGIN"/>
    <STRING id="STR_ID_IMPS_ERR_NO_INSTANT_MESSAGE"/>
    <STRING id="STR_ID_IMPS_ERR_INVITE_TIMEOUT"/>
    <STRING id="STR_ID_IMPS_ERR_MAX_INVITE_REPLY"/>
    <STRING id="STR_ID_IMPS_ERR_EXT_CONV_REJECTED"/>
    <STRING id="STR_ID_IMPS_ERR_RECIPIENT_NOT_SUPPORT"/>
    <STRING id="STR_ID_IMPS_ERR_BE_REJECTED"/>
    <STRING id="STR_ID_IMPS_ERR_NOT_GROUP_MEMBER"/>
    <STRING id="STR_ID_IMPS_EMPTY_FRIENDLY_NAME"/>
    <STRING id="STR_ID_IMPS_INVALID_FRIENDLY_NAME"/>
    <STRING id="STR_ID_IMPS_ERR_INSUFFICIENT_PRIVILEGE"/>
    <STRING id="STR_ID_IMPS_ERR_INSUFFICIENT_CREDIT"/>
    <STRING id="STR_ID_IMPS_VIEW_CONT_DETAIL"/>
    <STRING id="STR_ID_IMPS_NOT_READY"/>
    <STRING id="STR_ID_IMPS_INVITATION"/>
    <STRING id="STR_ID_IMPS_SERVER_DISCONNECT"/>
    <STRING id="STR_ID_IMPS_FORCED_OUT"/>
    <STRING id="STR_ID_IMPS_LEFT_CHAT_ROOM"/>
    <STRING id="STR_ID_IMPS_CHANGE_NICK_NAME"/>
    <STRING id="STR_ID_IMPS_SUBSCRIBE"/>
    <STRING id="STR_ID_IMPS_UNSUBSCRIBE"/>
    <STRING id="STR_ID_IMPS_ADD_DIRECTLY"/>
    <STRING id="STR_ID_IMPS_CHAT_ROOM_NAME"/>
    <STRING id="STR_ID_IMPS_ROOM_JOIN"/>
    <STRING id="STR_ID_IMPS_INVALID_GROUP_NAME"/>
    <STRING id="STR_ID_IMPS_GROUP_EXIST"/>
    <STRING id="STR_ID_IMPS_CHAT_ROOM_CLOSE"/>
    <STRING id="STR_ID_IMPS_NEW_INVITATION"/>
    <STRING id="STR_ID_IMPS_NEW_INVITE_REMINDER"/>
    <STRING id="STR_ID_IMPS_ROOM_ID"/>

    /* Maritail status */
    <STRING id="STR_ID_IMPS_NO_DISCLOSE"/>      /* do not change the order */
    <STRING id="STR_ID_IMPS_UNSPECIFIED"/>      /* do not change the order */
    <STRING id="STR_ID_IMPS_COHABITANT"/>       /* do not change the order */
    <STRING id="STR_ID_IMPS_DIVORCED"/>         /* do not change the order */
    <STRING id="STR_ID_IMPS_ENGAGED"/>          /* do not change the order */
    <STRING id="STR_ID_IMPS_MARRIED"/>          /* do not change the order */
    <STRING id="STR_ID_IMPS_SINGLE"/>           /* do not change the order */
    <STRING id="STR_ID_IMPS_WIDOWED"/>          /* do not change the order */

    <STRING id="STR_ID_IMPS_SUBSCRIBE_NOTIFY"/>
    <STRING id="STR_ID_IMPS_UNSUBSCRIBE_NOTIFY"/>
    <STRING id="STR_ID_IMPS_PRESENCE"/>
    <STRING id="STR_ID_IMPS_PUBLIC_PROFILE_1"/>
    <STRING id="STR_ID_IMPS_PUBLIC_PROFILE_2"/>
    <STRING id="STR_ID_IMPS_MALE"/>
    <STRING id="STR_ID_IMPS_FEMALE"/>
    <STRING id="STR_ID_IMPS_AGE"/>
    <STRING id="STR_ID_IMPS_FRIENDLY_NAME"/>
    <STRING id="STR_ID_IMPS_CITY"/>
    <STRING id="STR_ID_IMPS_FREE_TEXT"/>
    <STRING id="STR_ID_IMPS_GENDER"/>
    <STRING id="STR_ID_IMPS_INTENTION"/>
    <STRING id="STR_ID_IMPS_HOBBIES"/>
    <STRING id="STR_ID_IMPS_MARITAL_STATUS"/>
    <STRING id="STR_ID_IMPS_FIRST_NAME"/>
    <STRING id="STR_ID_IMPS_LAST_NAME"/>
    <STRING id="STR_ID_IMPS_USERID"/>
    <STRING id="STR_ID_IMPS_MAX_AGE"/>
    <STRING id="STR_ID_IMPS_MIN_AGE"/>
    <STRING id="STR_ID_IMPS_AUTO_JOINED_USER"/>
    <STRING id="STR_ID_IMPS_SEND_FILE"/>
    <STRING id="STR_ID_IMPS_SYSTEM_MESSAGE"/>
    <STRING id="STR_ID_IMPS_SYSTEM_MESSAGE_HELP"/>
    <STRING id="STR_ID_IMPS_VERIFICATION_KEY"/>
    <STRING id="STR_ID_IMPS_ADD_TO_ANOTHER_LIST"/>
    <STRING id="STR_ID_IMPS_AUTHORIZATION_CHANGED"/>
    <STRING id="STR_ID_IMPS_AUTHORIZATION_NEEDED_CONTACTLIST"/>
    <STRING id="STR_ID_IMPS_AUTHORIZATION_NEEDED_DEFAULTLIST"/>
    <STRING id="STR_ID_IMPS_AUTHORIZATION_NEEDED_USER"/>
    <STRING id="STR_ID_IMPS_BLOCK_LIST_CHANGED"/>
    <STRING id="STR_ID_IMPS_BLOCK_LIST_USAGECHANGE"/>
    <STRING id="STR_ID_IMPS_CONTACT_LIST_CREATED"/>
    <STRING id="STR_ID_IMPS_CONTACT_LIST_CHANGED"/>
    <STRING id="STR_ID_IMPS_CONTACT_LIST_DELETED"/>
    <STRING id="STR_ID_IMPS_GRANT_LIST_CHANGED"/>
    <STRING id="STR_ID_IMPS_GRANT_LIST_USAGECHANGE"/>
    <STRING id="STR_ID_IMPS_GROUP_CREATED"/>
    <STRING id="STR_ID_IMPS_GROUP_DELETED"/>
    <STRING id="STR_ID_IMPS_GROUP_MEMBERACCESS_UPDATED"/>
    <STRING id="STR_ID_IMPS_GROUP_MEMBER_UPDATED"/>
    <STRING id="STR_ID_IMPS_GROUP_MEMBERSHIP_GRANTED"/>
    <STRING id="STR_ID_IMPS_GROUP_MEMBERSHIP_REVOKED"/>
    <STRING id="STR_ID_IMPS_GROUP_REMOVED"/>
    <STRING id="STR_ID_IMPS_INVITATION_ACCEPTED"/>
    <STRING id="STR_ID_IMPS_INVITATION_CANCELLED"/>
    <STRING id="STR_ID_IMPS_INVITATION_REJECTED"/>
    <STRING id="STR_ID_IMPS_ONLINEETEMHANDLING_UPDATED"/>
    <STRING id="STR_ID_IMPS_PUBLIC_PROFILE_UPDATED"/>
    <STRING id="STR_ID_IMPS_SESSION_PRIORITY_ADJUSTED"/>
    <STRING id="STR_ID_IMPS_USER_ID_CHANGED"/>
    <STRING id="STR_ID_IMPS_RECEIVE_NEW_FILE"/>
    <STRING id="STR_ID_IMPS_NEW_PA_AUTH"/>
    <STRING id="STR_ID_IMPS_ACCEPT"/>
    <STRING id="STR_ID_IMPS_REJECT"/>
    <STRING id="STR_ID_IMPS_PA_AUTH_NOTE"/>
    <STRING id="STR_ID_IMPS_NEW_SYSTEM_MESSAGE"/>
    <STRING id="STR_ID_IMPS_CONTENT_POLICY_EXTRA_COST"/>
    <STRING id="STR_ID_IMPS_CONTENT_POLICY_REJECT"/>
    <STRING id="STR_ID_IMPS_NEW_FILE_FROM"/>
    <STRING id="STR_ID_IMPS_ERR_PP_NOT_COMPLETE"/>
    <STRING id="STR_ID_IMPS_TEXT_VERIFICATION"/>
    <STRING id="STR_ID_IMPS_URL_VERIFICATION"/>
    <STRING id="STR_ID_IMPS_ACCOUNT_INFO"/>
    <STRING id="STR_ID_IMPS_INVITE_ADD_FRIEND"/>
    <STRING id="STR_ID_IMPS_SETTING"/>
    <STRING id="STR_ID_IMPS_VOICE_MESSAGE"/>
    <STRING id="STR_ID_IMPS_PICTURE_MESSAGE"/>
    <STRING id="STR_ID_IMPS_VIDEO_MESSAGE"/>
    <STRING id="STR_ID_IMPS_FILE_SIZE"/>
    <STRING id="STR_ID_IMPS_FILE_TYPE"/>
    <STRING id="STR_ID_IMPS_SENDER"/>
    <STRING id="STR_ID_IMPS_NO_CHAT_HISTORY"/>
    <STRING id="STR_ID_IMPS_OFFLINE_MSG"/>
    <STRING id="STR_ID_IMPS_NEW_MSG"/>
    <STRING id="STR_ID_IMPS_RECONN"/>
    <STRING id="STR_ID_IMPS_RECONN_FAIL"/>
    <STRING id="STR_ID_IMPS_FILE_RECV_DONE"/>
    <STRING id="STR_ID_IMPS_EMPTY_ALIAS"/>
    <STRING id="STR_ID_IMPS_EMPTY_MOBILE_NUMBER"/>
    <STRING id="STR_ID_IMPS_MOBILE_NUMBER_TOO_LONG"/>
    <STRING id="STR_ID_IMPS_VIEW_PUBLIC_PROFILE"/>
    <STRING id="STR_ID_IMPS_ADD_TO_GROUP"/>
    <STRING id="STR_ID_IMPS_PUBLIC_PROFILE"/>
    
    <STRING id="STR_ID_IMPS_DEVICE_TYPE"/>              /* do not change the order */
    <STRING id="STR_ID_IMPS_DEVICE_TYPE_INVISIBLE"/>    /* do not change the order */
    <STRING id="STR_ID_IMPS_DEVICE_TYPE_MOBILE"/>       /* do not change the order */
    <STRING id="STR_ID_IMPS_DEVICE_TYPE_PC"/>           /* do not change the order */
    <STRING id="STR_ID_IMPS_DEVICE_TYPE_PDA"/>          /* do not change the order */
    <STRING id="STR_ID_IMPS_DEVICE_TYPE_CLI"/>          /* do not change the order */
    <STRING id="STR_ID_IMPS_DEVICE_TYPE_OTHER"/>        /* do not change the order */

    <STRING id="STR_ID_IMPS_CONTACT_NOT_AVAILABLE"/>
    <STRING id="STR_ID_IMPS_NETWORK_IND"/>
    <STRING id="STR_ID_IMPS_EMPTY_FILE"/>
    <STRING id="STR_ID_IMPS_GET_MESSAGE_FAIL"/>
    <STRING id="STR_ID_IMPS_REJECT_MESSAGE_FAIL"/>
    <STRING id="STR_ID_IMPS_AGREE_OTHER_JOIN"/>
    <STRING id="STR_ID_IMPS_INVITE_OTHER_JOIN"/>
    <STRING id="STR_ID_IMPS_FORBID_SEND_IM"/>
    <STRING id="STR_ID_IMPS_ACCEPT_INVITE"/>
    <STRING id="STR_ID_IMPS_NO_SPACE_TO_GET_FILE"/>
    <STRING id="STR_ID_IMPS_NEW"/>
    <STRING id="STR_ID_IMPS_INVALID_ALIAS"/>
    <STRING id="STR_ID_IMPS_FMGR_IMAGE_NOT_SUPPORT"/>
    <STRING id="STR_ID_IMPS_EDIT_DISPLAY_NAME_ASK"/>
    <STRING id="STR_ID_IMPS_EDIT_FRIENDLY_NAME_ASK"/>
    <STRING id="STR_ID_IMPS_EDIT_ALIAS_ASK"/>
    <STRING id="STR_ID_IMPS_VIEW_ASK"/>
    <STRING id="STR_ID_IMPS_PLAY_ASK"/>
    <STRING id="STR_ID_IMPS_SEND_ASK"/>
    <STRING id="STR_ID_IMPS_CLOSE_ASK"/>
    <STRING id="STR_ID_IMPS_CANCEL_ASK"/>
    <STRING id="STR_ID_IMPS_REJECT_ASK"/>
    <STRING id="STR_ID_IMPS_WITHDRAW_CONT_ASK"/>
    <STRING id="STR_ID_IMPS_INVITE_ASK"/>
    <STRING id="STR_ID_IMPS_LOGIN_ASK"/>
    <STRING id="STR_ID_IMPS_LOGOUT_ASK"/>
    <STRING id="STR_ID_IMPS_EXIT_ASK"/>
    <STRING id="STR_ID_IMPS_JOIN_ASK"/>
    <STRING id="STR_ID_IMPS_OPEN_ASK"/>
    <STRING id="STR_ID_IMPS_GRANT_CONTACT_ASK"/>
    <STRING id="STR_ID_IMPS_BLOCK_CONTACT_ASK"/>
    <STRING id="STR_ID_IMPS_DELETE_ASK"/>
    <STRING id="STR_ID_IMPS_NEW_ASK"/>
    <STRING id="STR_ID_IMPS_ADD_ASK"/>
    <STRING id="STR_ID_IMPS_FOLD_CONT_LIST"/>
    <STRING id="STR_ID_IMPS_UNWRAP_CONT_LIST"/>
    <STRING id="STR_ID_IMPS_CBM_AUTO_LOGIN"/>
    <STRING id="STR_ID_IMPS_ERR_USER_CANCEL"/>
    <STRING id="STR_ID_IMPS_ERR_INVALID_ROOM_NAME"/>
    <STRING id="STR_ID_IMPS_GIVE_UP_ASK"/>
    <STRING id="STR_ID_IMPS_SETTINGS"/>
    <STRING id="STR_ID_IMPS_PROF_SETTING"/>
    <STRING id="STR_ID_IMPS_SETTING_MY_PROF"/>
    <STRING id="STR_ID_IMPS_SETTING_NOTIFY"/>
    <STRING id="STR_ID_IMPS_SETTING_MS_NOTIFY"/>
    <STRING id="STR_ID_IMPS_SETTING_PR_NOTIFY"/>
    <STRING id="STR_ID_IMPS_AUDIO"/>
    <STRING id="STR_ID_IMPS_NO_AUDIO_VIBRATION"/>   /* do not change the order */
    <STRING id="STR_ID_IMPS_AUDIO_ONLY"/>           /* do not change the order */
    <STRING id="STR_ID_IMPS_AUDIO_VIBRATION"/>      /* do not change the order */
    <STRING id="STR_ID_IMPS_VIBRATION_ONLY"/>       /* do not change the order */
    <STRING id="STR_ID_IMPS_VISUAL"/>               /* do not change the order */
    <STRING id="STR_ID_IMPS_NO_VISUAL"/>            /* do not change the order */
    <STRING id="STR_ID_IMPS_SETTING_CONNECT"/>
    <STRING id="STR_ID_IMPS_SETTING_AUTHORIZE"/>
    <STRING id="STR_ID_IMPS_REACTIVE_ON"/>          /* do not change the order */
    <STRING id="STR_ID_IMPS_REACTIVE_OFF"/>         /* do not change the order */
    <STRING id="STR_ID_IMPS_SETTING_LINK_PROF"/>
    <STRING id="STR_ID_IMPS_SETTING_AUTO_LOGIN"/>
    <STRING id="STR_ID_IMPS_SETTING_AUTO_START"/>
    <STRING id="STR_ID_IMPS_SETTING_DEACTIVE"/>
    <STRING id="STR_ID_IMPS_SETTING_ACTIVE"/>
    <STRING id="STR_ID_IMPS_SETTING_TONE"/>
    <STRING id="STR_ID_IMPS_SETTING_TONE_CONTACT_ONLINE"/>
    <STRING id="STR_ID_IMPS_SETTING_TONE_NEW_MESSAGE"/>
    <STRING id="STR_ID_IMPS_SETTING_TONE_NEW_INVITATION"/>
    <STRING id="STR_ID_IMPS_SETTING_TONE_CHATROOM_NOTIFICATION"/>
    <STRING id="STR_ID_IMPS_ADD_CONT_GROUP"/>
    <STRING id="STR_ID_IMPS_CREATE_GROUP"/>
    <STRING id="STR_ID_IMPS_DELETE_GROUP"/>
    <STRING id="STR_ID_IMPS_CONT_MANAGE"/>
    <STRING id="STR_ID_IMPS_MOVE_CONTACT"/>
    <STRING id="STR_ID_IMPS_CONT_LIST_REFRESH"/>
    <STRING id="STR_ID_IMPS_CONT_LIST_HELP"/>
    <STRING id="STR_ID_IMPS_CONT_HELP"/>
    <STRING id="STR_ID_IMPS_TAB_BUDDIES"/>
    <STRING id="STR_ID_IMPS_MOVE_CONT_FAIL"/>
    <STRING id="STR_ID_IMPS_NEW_FILE"/>
    <STRING id="STR_ID_IMPS_EMAIL_DOMAIN"/>
    <STRING id="STR_ID_IMPS_SEARCH_BY_EMAIL"/>
    <STRING id="STR_ID_IMPS_SEARCH_BY_NUMB"/>
    <STRING id="STR_ID_IMPS_DEFAULT_CONT_LIST"/>
    <STRING id="STR_ID_IMPS_NEW_IM"/>
    <STRING id="STR_ID_IMPS_OWNER"/>
    <STRING id="STR_ID_IMPS_WELCOME_TEXT"/>
    <STRING id="STR_ID_IMPS_JOIN"/>
    <STRING id="STR_ID_IMPS_CONT_DETAILS"/>
    <STRING id="STR_ID_IMPS_MOVE_ASK"/>
    <STRING id="STR_ID_IMPS_EMPTY_NICKNAME"/>
    <STRING id="STR_ID_IMPS_COUNTRY_CODE"/>

    /* ISO 3166-1 country code, do not change the order */
    <STRING id="STR_ID_IMPS_CC_BEGIN"/>
    <STRING id="STR_ID_IMPS_AD"/>    /* Andorra */
    <STRING id="STR_ID_IMPS_AE"/>    /* United Arab Emirates */
    <STRING id="STR_ID_IMPS_AF"/>    /* Afghanistan */
    <STRING id="STR_ID_IMPS_AG"/>    /* Antigua and Barbuda */
    <STRING id="STR_ID_IMPS_AL"/>    /* Albania */
    <STRING id="STR_ID_IMPS_AM"/>    /* Armenia */
    <STRING id="STR_ID_IMPS_AO"/>    /* Angola */
    <STRING id="STR_ID_IMPS_AR"/>    /* Argentina */
    <STRING id="STR_ID_IMPS_AT"/>    /* Austria */
    <STRING id="STR_ID_IMPS_AU"/>    /* Australia */
    <STRING id="STR_ID_IMPS_AZ"/>    /* Azerbaijan */
    <STRING id="STR_ID_IMPS_BA"/>    /* Bosnia Hercegovina */
    <STRING id="STR_ID_IMPS_BB"/>    /* Barbados */
    <STRING id="STR_ID_IMPS_BD"/>    /* Bangladesh */
    <STRING id="STR_ID_IMPS_BE"/>    /* Belgium */
    <STRING id="STR_ID_IMPS_BF"/>    /* Burkina Faso */
    <STRING id="STR_ID_IMPS_BG"/>    /* Bulgaria */
    <STRING id="STR_ID_IMPS_BH"/>    /* Bahrain */
    <STRING id="STR_ID_IMPS_BI"/>    /* Burundi */
    <STRING id="STR_ID_IMPS_BJ"/>    /* Benin */
    <STRING id="STR_ID_IMPS_BN"/>    /* Brunei Darussalam */
    <STRING id="STR_ID_IMPS_BO"/>    /* Bolivia */
    <STRING id="STR_ID_IMPS_BR"/>    /* Brazil */
    <STRING id="STR_ID_IMPS_BS"/>    /* Bahamas */
    <STRING id="STR_ID_IMPS_BT"/>    /* Bhutan */
    <STRING id="STR_ID_IMPS_BW"/>    /* Botswana */
    <STRING id="STR_ID_IMPS_BY"/>    /* Belarus */
    <STRING id="STR_ID_IMPS_BZ"/>    /* Belize */
    <STRING id="STR_ID_IMPS_CA"/>    /* Canada */
    <STRING id="STR_ID_IMPS_CD"/>    /* Democratic Republic of the Congo */
    <STRING id="STR_ID_IMPS_CF"/>    /* Central African Republic */
    <STRING id="STR_ID_IMPS_CG"/>    /* Congo */
    <STRING id="STR_ID_IMPS_CH"/>    /* Switzerland */
    <STRING id="STR_ID_IMPS_CI"/>    /* Ivory Coast */
    <STRING id="STR_ID_IMPS_CL"/>    /* Chile */
    <STRING id="STR_ID_IMPS_CM"/>    /* Cameroon */
    <STRING id="STR_ID_IMPS_CN"/>    /* China */
    <STRING id="STR_ID_IMPS_CO"/>    /* Colombia  */
    <STRING id="STR_ID_IMPS_CR"/>    /* Costa Rica */
    <STRING id="STR_ID_IMPS_CU"/>    /* Cuba  */
    <STRING id="STR_ID_IMPS_CV"/>    /* Cape Verde */
    <STRING id="STR_ID_IMPS_CY"/>    /* Cyprus */
    <STRING id="STR_ID_IMPS_CZ"/>    /* Czech Republic */
    <STRING id="STR_ID_IMPS_DE"/>    /* Germany */
    <STRING id="STR_ID_IMPS_DJ"/>    /* Djibouti  */
    <STRING id="STR_ID_IMPS_DK"/>    /* Denmark  */
    <STRING id="STR_ID_IMPS_DM"/>    /* Dominica  */
    <STRING id="STR_ID_IMPS_DO"/>    /* Dominican Republic */
    <STRING id="STR_ID_IMPS_DZ"/>    /* Algeria  */
    <STRING id="STR_ID_IMPS_EC"/>    /* Ecuador  */
    <STRING id="STR_ID_IMPS_EE"/>    /* Estonia  */
    <STRING id="STR_ID_IMPS_EG"/>    /* Egypt  */
    <STRING id="STR_ID_IMPS_ER"/>    /* Eritrea */
    <STRING id="STR_ID_IMPS_ES"/>    /* Spain */
    <STRING id="STR_ID_IMPS_ET"/>    /* Ethiopia  */
    <STRING id="STR_ID_IMPS_FI"/>    /* Finland  */
    <STRING id="STR_ID_IMPS_FJ"/>    /* Fiji  */
    <STRING id="STR_ID_IMPS_FM"/>    /* Falkland Islands */
    <STRING id="STR_ID_IMPS_FR"/>    /* France */
    <STRING id="STR_ID_IMPS_GA"/>    /* Gobon */
    <STRING id="STR_ID_IMPS_GB"/>    /* Great Britain (UK) */
    <STRING id="STR_ID_IMPS_GD"/>    /* Grenada */
    <STRING id="STR_ID_IMPS_GE"/>    /* Georgia */
    <STRING id="STR_ID_IMPS_GH"/>    /* Ghana */
    <STRING id="STR_ID_IMPS_GM"/>    /* Gambia */
    <STRING id="STR_ID_IMPS_GN"/>    /* Guynea */
    <STRING id="STR_ID_IMPS_GQ"/>    /* Equatorial Guinea */
    <STRING id="STR_ID_IMPS_GR"/>    /* Greece */
    <STRING id="STR_ID_IMPS_GT"/>    /* Guatemala */
    <STRING id="STR_ID_IMPS_GU"/>    /* Guam Islands */
    <STRING id="STR_ID_IMPS_GW"/>    /* Guinea-Bissau */
    <STRING id="STR_ID_IMPS_GY"/>    /* Guyana */
    <STRING id="STR_ID_IMPS_HK"/>    /* Hong Kong */
    <STRING id="STR_ID_IMPS_HN"/>    /* Honduras */
    <STRING id="STR_ID_IMPS_HR"/>    /* Croatia */
    <STRING id="STR_ID_IMPS_HT"/>    /* Haiti */
    <STRING id="STR_ID_IMPS_HU"/>    /* Hungary */
    <STRING id="STR_ID_IMPS_ID"/>    /* Indonesia */
    <STRING id="STR_ID_IMPS_IE"/>    /* Ireland */
    <STRING id="STR_ID_IMPS_IL"/>    /* Israel */
    <STRING id="STR_ID_IMPS_IN"/>    /* India */
    <STRING id="STR_ID_IMPS_IQ"/>    /* Iraq */
    <STRING id="STR_ID_IMPS_IR"/>    /* Iran */
    <STRING id="STR_ID_IMPS_IS"/>    /* Iceland */
    <STRING id="STR_ID_IMPS_IT"/>    /* Italy */
    <STRING id="STR_ID_IMPS_JM"/>    /* Jamaica */
    <STRING id="STR_ID_IMPS_JO"/>    /* Jordan */
    <STRING id="STR_ID_IMPS_JP"/>    /* Japan */
    <STRING id="STR_ID_IMPS_KE"/>    /* Kenya */
    <STRING id="STR_ID_IMPS_KG"/>    /* Kyrgyzstan */
    <STRING id="STR_ID_IMPS_KH"/>    /* Cambodia */
    <STRING id="STR_ID_IMPS_KI"/>    /* Kiribati */
    <STRING id="STR_ID_IMPS_KM"/>    /* Comoros */
    <STRING id="STR_ID_IMPS_KN"/>    /* St. Kitts & Nevis */
    <STRING id="STR_ID_IMPS_KP"/>    /* Korea-North */
    <STRING id="STR_ID_IMPS_KR"/>    /* Korea-South */
    <STRING id="STR_ID_IMPS_KW"/>    /* Kuwait */
    <STRING id="STR_ID_IMPS_KZ"/>    /* Kazakhstan */
    <STRING id="STR_ID_IMPS_LA"/>    /* Lao People's Republic */
    <STRING id="STR_ID_IMPS_LB"/>    /* Lebanon */
    <STRING id="STR_ID_IMPS_LC"/>    /* St. Lucia */
    <STRING id="STR_ID_IMPS_LI"/>    /* Liechtenstein */
    <STRING id="STR_ID_IMPS_LK"/>    /* Sri Lanka */
    <STRING id="STR_ID_IMPS_LR"/>    /* Liberia */
    <STRING id="STR_ID_IMPS_LS"/>    /* Lesotho */
    <STRING id="STR_ID_IMPS_LT"/>    /* Lithuania */
    <STRING id="STR_ID_IMPS_LU"/>    /* Luxembourg */
    <STRING id="STR_ID_IMPS_LV"/>    /* Latvia */
    <STRING id="STR_ID_IMPS_LY"/>    /* Libya */
    <STRING id="STR_ID_IMPS_MA"/>    /* Morocco */
    <STRING id="STR_ID_IMPS_MC"/>    /* Monaco */
    <STRING id="STR_ID_IMPS_MD"/>    /* Moldova */
    <STRING id="STR_ID_IMPS_ME"/>    /* Montenegro */
    <STRING id="STR_ID_IMPS_MG"/>    /* Madagascar */
    <STRING id="STR_ID_IMPS_MH"/>    /* Marshall Islands */
    <STRING id="STR_ID_IMPS_MK"/>    /* Mauritius */
    <STRING id="STR_ID_IMPS_ML"/>    /* Mali */
    <STRING id="STR_ID_IMPS_MM"/>    /* Myanmar */
    <STRING id="STR_ID_IMPS_MN"/>    /* Mongolia */
    <STRING id="STR_ID_IMPS_MO"/>    /* Macao */
    <STRING id="STR_ID_IMPS_MR"/>    /* Mauritania */
    <STRING id="STR_ID_IMPS_MT"/>    /* Malta */
    <STRING id="STR_ID_IMPS_MU"/>    /* Mauritius */
    <STRING id="STR_ID_IMPS_MV"/>    /* Maldives */
    <STRING id="STR_ID_IMPS_MW"/>    /* Malawi */
    <STRING id="STR_ID_IMPS_MX"/>    /* Mexico */
    <STRING id="STR_ID_IMPS_MY"/>    /* Malaysia */
    <STRING id="STR_ID_IMPS_MZ"/>    /* Mozambique */
    <STRING id="STR_ID_IMPS_NA"/>    /* Namibia */
    <STRING id="STR_ID_IMPS_NE"/>    /* Niger */
    <STRING id="STR_ID_IMPS_NG"/>    /* Nigeria */
    <STRING id="STR_ID_IMPS_NI"/>    /* Nicaragua */
    <STRING id="STR_ID_IMPS_NL"/>    /* Netherlands */
    <STRING id="STR_ID_IMPS_NO"/>    /* Norway */
    <STRING id="STR_ID_IMPS_NP"/>    /* Nepal */
    <STRING id="STR_ID_IMPS_NR"/>    /* Nauru */
    <STRING id="STR_ID_IMPS_NZ"/>    /* New Zealand */
    <STRING id="STR_ID_IMPS_OM"/>    /* Oman */
    <STRING id="STR_ID_IMPS_PA"/>    /* Paname */
    <STRING id="STR_ID_IMPS_PE"/>    /* Peru */ 
    <STRING id="STR_ID_IMPS_PG"/>    /* Papua New Guinea */
    <STRING id="STR_ID_IMPS_PH"/>    /* Philippines */
    <STRING id="STR_ID_IMPS_PK"/>    /* Pakistan */
    <STRING id="STR_ID_IMPS_PL"/>    /* Poland */
    <STRING id="STR_ID_IMPS_PR"/>    /* Puerto Rico */
    <STRING id="STR_ID_IMPS_PS"/>    /* Palestinian territories */
    <STRING id="STR_ID_IMPS_PT"/>    /* Portugal */
    <STRING id="STR_ID_IMPS_PW"/>    /* Palau */
    <STRING id="STR_ID_IMPS_PY"/>    /* Paraguay */
    <STRING id="STR_ID_IMPS_QA"/>    /* Qatar */
    <STRING id="STR_ID_IMPS_RE"/>    /* Reunion */
    <STRING id="STR_ID_IMPS_RO"/>    /* Romania */
    <STRING id="STR_ID_IMPS_RS"/>    /* Serbia */
    <STRING id="STR_ID_IMPS_RU"/>    /* Russian Federation */
    <STRING id="STR_ID_IMPS_RW"/>    /* Rwanda */
    <STRING id="STR_ID_IMPS_SA"/>    /* Saudi Arabia */
    <STRING id="STR_ID_IMPS_SB"/>    /* Solomon Islands */
    <STRING id="STR_ID_IMPS_SC"/>    /* Seychelles */
    <STRING id="STR_ID_IMPS_SD"/>    /* Sudan */
    <STRING id="STR_ID_IMPS_SE"/>    /* Sweden */
    <STRING id="STR_ID_IMPS_SG"/>    /* Singapore */
    <STRING id="STR_ID_IMPS_SI"/>    /* Slovenia */
    <STRING id="STR_ID_IMPS_SK"/>    /* Slovakia */
    <STRING id="STR_ID_IMPS_SL"/>    /* Sierra Leone */
    <STRING id="STR_ID_IMPS_SM"/>    /* San Marino */
    <STRING id="STR_ID_IMPS_SN"/>    /* Senegal */
    <STRING id="STR_ID_IMPS_SO"/>    /* Somalia */
    <STRING id="STR_ID_IMPS_SR"/>    /* Suriname */
    <STRING id="STR_ID_IMPS_ST"/>    /* Sao Tome & Principe */
    <STRING id="STR_ID_IMPS_SV"/>    /* El Salvador */
    <STRING id="STR_ID_IMPS_SY"/>    /* Syrian Arab Republic */
    <STRING id="STR_ID_IMPS_SZ"/>    /* Swaziland */
    <STRING id="STR_ID_IMPS_TD"/>    /* Chad */
    <STRING id="STR_ID_IMPS_TG"/>    /* Togo */
    <STRING id="STR_ID_IMPS_TH"/>    /* Thailand */
    <STRING id="STR_ID_IMPS_TJ"/>    /* Tajikistan */
    <STRING id="STR_ID_IMPS_TL"/>    /* Timor-Leste */
    <STRING id="STR_ID_IMPS_TM"/>    /* Turkmenistan */
    <STRING id="STR_ID_IMPS_TN"/>    /* Tunisia */
    <STRING id="STR_ID_IMPS_TO"/>    /* Tonga */
    <STRING id="STR_ID_IMPS_TR"/>    /* Turkey */
    <STRING id="STR_ID_IMPS_TT"/>    /* Trinidad & Tobago */
    <STRING id="STR_ID_IMPS_TV"/>    /* Tuvalu */
    <STRING id="STR_ID_IMPS_TW"/>    /* Taiwan */
    <STRING id="STR_ID_IMPS_TZ"/>    /* Tanzania */
    <STRING id="STR_ID_IMPS_UA"/>    /* Ukrainian SSR */
    <STRING id="STR_ID_IMPS_UG"/>    /* Uganda */
    <STRING id="STR_ID_IMPS_US"/>    /* United States */
    <STRING id="STR_ID_IMPS_UY"/>    /* Uruguay */
    <STRING id="STR_ID_IMPS_UZ"/>    /* Uzbekistan */
    <STRING id="STR_ID_IMPS_VA"/>    /* Vatican City State */
    <STRING id="STR_ID_IMPS_VC"/>    /* St. Vincent & the Grenadines */
    <STRING id="STR_ID_IMPS_VE"/>    /* Venezuela */
    <STRING id="STR_ID_IMPS_VN"/>    /* Vietnam */
    <STRING id="STR_ID_IMPS_VU"/>    /* Vanuatu */
    <STRING id="STR_ID_IMPS_WS"/>    /* Samoa */
    <STRING id="STR_ID_IMPS_YE"/>    /* Yemen */
    <STRING id="STR_ID_IMPS_YT"/>    /* Mayotte */
    <STRING id="STR_ID_IMPS_ZA"/>    /* South Africa */
    <STRING id="STR_ID_IMPS_ZM"/>    /* Zambia */
    <STRING id="STR_ID_IMPS_ZW"/>    /* Zimbabwe */
    <STRING id="STR_ID_IMPS_CC_END"/>
    /* ISO 3166-1 country code end, do not change the order */

    <STRING id="STR_ID_IMPS_GROUP_NAME"/>
    <STRING id="STR_ID_IMPS_GROUP_DISPLAY_NAME"/>
    <STRING id="STR_ID_IMPS_INPUT_NUM_DIRECT"/>
    <STRING id="STR_ID_IMPS_LOAD_NUM_FROM_ADDRESS"/>
    <STRING id="STR_ID_IMPS_USER_CONNECTED"/>
    <STRING id="STR_ID_IMPS_USER_DISCONNECTED"/>
    <STRING id="STR_ID_IMPS_STATUS_UPDATE_DONE"/>
    <STRING id="STR_ID_IMPS_STATUS_UPDATE_FAIL"/>
    <STRING id="STR_ID_IMPS_RESIZED"/>
    <STRING id="STR_ID_IMPS_COLON"/>
    <STRING id="STR_ID_IMPS_CALL_ASK"/>    /* click to call */
    <STRING id="STR_ID_IMPS_SAVE_TO_PHB_ASK"/>
    <STRING id="STR_ID_IMPS_GOTO_ASK"/>
    <STRING id="STR_ID_IMPS_MANAGE_CONVERSATION"/>
    <STRING id="STR_ID_IMPS_VIEW_CONVERSATION"/>
    <STRING id="STR_ID_IMPS_SAVE_CONVERSATION"/>
    <STRING id="STR_ID_IMPS_DEL_CONVERSATION"/>
    <STRING id="STR_ID_IMPS_FAIL_TO_DELETE"/>
    <STRING id="STR_ID_IMPS_CONVERSATION_FILE_NOT_EXIST"/>
    <STRING id="STR_ID_IMPS_NOT_SAVED_NUMBER_TOO_LONG"/>
    <STRING id="STR_ID_IMPS_VIEW_CONVERSATION_NEXT"/>
    <STRING id="STR_ID_IMPS_VIEW_CONVERSATION_PRE"/>
    <STRING id="STR_ID_IMPS_VIEW_CONVERSATION_JUMP"/>
    <STRING id="STR_ID_IMPS_INVALID_PAGE"/>
    <STRING id="STR_ID_IMPS_OPEN_WAIT"/>
    <STRING id="STR_ID_IMPS_OPEN_TRY_LATER"/>

/*
 * Common version strings
 */
#ifndef __MMI_OP11_IMPS__
    <STRING id="STR_ID_IMPS_LOGIN_SECURE"/>
    <STRING id="STR_ID_IMPS_PROFILE1"/>
    <STRING id="STR_ID_IMPS_PROFILE2"/>
    <STRING id="STR_ID_IMPS_PROFILE3"/>
    <STRING id="STR_ID_IMPS_PROF_CONN"/>
    <STRING id="STR_ID_IMPS_PROF_NAME"/>
    <STRING id="STR_ID_IMPS_LOGIN_MODE"/>
    <STRING id="STR_ID_IMPS_PROF_NO_CONFIG"/>
#endif /* #ifndef __MMI_OP11_IMPS__ */


    <!---------------------------------------------- Image Resource Area ---------------------------------------------->

    /* common images, used on both orange project or non-orange project */
    <IMAGE id="IMG_ID_IMPS_MENU"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\SB_IMPS.bmp"</IMAGE>
    
#ifdef __MMI_OP11_IMPS__
    /* 
     * Orange only images 
     */
    <IMAGE id="IMG_ID_IMPS_LOGO"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Logo_ani.gif"</IMAGE>

    /* emoticons, do not change the order */
    <IMAGE id="IMG_ID_IMPS_SMILE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Smile.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SHOUT"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Shoud.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_WINK"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Wink.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_TONGUE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Tongue.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SAD"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Sad.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SUNGLASSES"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Sunglasses.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_LIPS1"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Lips_face.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_PUZZLED"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Puzzled.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SLEEP"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Sleep.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BIG_GRIN"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_BigGrin.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_DEVIL"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Devil.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_TEAR"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Tear.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SUPERSAD"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Supersad.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BLUSH"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Blush.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ANGEL"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Angel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_EYEBROW"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Eyebrow.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_EYEROLL"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Eyeroll.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_NERD"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Nerd.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_PUKE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Puke.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SARCASTIC"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Sarcastic.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_WHEEP"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Wheep.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ANGRY"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Angry.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CAKE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Cake.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BEER"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Beer.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BROKEN_HEART"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_BrokenHeart.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_HEART"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Heart.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_GIFT"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Gift.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CAT"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Cat.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_COKTAIL"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Coktail.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_TEETH"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Teeth.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_THINKING"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Thinking.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ZIPIT"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Zipit.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_GOSSIP"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Gossip.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_PARTY"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Party.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_DISGUST"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Disgust.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_HUG1"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Hug_right.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SHEEP"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Sheep.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_HUG2"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Hug_left.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_THUMB_UP"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Thumb_up.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_COFFEE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Coffee.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_LIPS2"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Lips.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_THUMB_DOWN"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_thumb_down.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_WILTED_ROSE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Wited_rose.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_DOG"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\emotions\\\\IM_Dog.bmp"</IMAGE>
    /* emoticons end */

    /* status, do not change the order*/
    <IMAGE id="IMG_ID_IMPS_REFRESH"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_OFFLINE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Offline.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ONLINE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Available.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BUSY"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Busy.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_AWAY"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_AWAY.bmp"</IMAGE>
    /* status end*/
   
    <IMAGE id="IMG_ID_IMPS_MESSAGE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_msgNew.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_EMPTY_MESSAGE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_msgEmpty.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BLOCK"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Block.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_OFFLINE_BLOCK"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_OfflineBlock.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BLOCKED"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Blocked.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_GROUP_FOLD"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Fold.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_GROUP_UNWRAP"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Unwrap.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ABOUT_DEFAULT"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Default.gif"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CONT_LIST"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_ContactList.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CHAT_ROOM"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_ChatRoom.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_TALK"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_Talk.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CHATROOM_MENU"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_IMGroup.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_TALK_MENU"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_IMConversation.bmp"</IMAGE>

    <IMAGE id="IMG_ID_IMPS_USER_CONNECTED"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Connected.gif"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_USER_DISCONNECTED"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Disconnect.gif"</IMAGE>


#else /* __MMI_OP11_IMPS__ */

    /* 
     * Non-orange only images 
     */

    /* emoticons, do not change the order */
    <IMAGE id="IMG_ID_IMPS_HAPPY">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Happy.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SAD">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Sad.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ANGRY">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Angry.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_JEALOUS">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Jealous.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ASHAMED">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Ashamed.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_INVINCIBLE">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Invincible.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_IN_LOVE">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Inlove.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_SLEEPY">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Sleepy.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BORED">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Bored.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_EXCITED">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Excited.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ANXIOUS">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Anxious.bmp"</IMAGE>
    /* emoticons end */

    /* status, do not change the order*/
    <IMAGE id="IMG_ID_IMPS_REFRESH">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Refresh.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_OFFLINE">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Offline.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ONLINE">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Online.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BUSY">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Busy.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_AWAY">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_AWAY.bmp"</IMAGE>
    /* status end*/

    <IMAGE id="IMG_ID_IMPS_MESSAGE">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Message.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_EMPTY_MESSAGE"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_msgEmpty.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BLOCK"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Block.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_OFFLINE_BLOCK"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_OfflineBlock.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_BLOCKED"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Blocked.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_GROUP_FOLD">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Fold.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_GROUP_UNWRAP">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Listview\\\\IM_Unwrap.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_ABOUT_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\About\\\\IM_Default.gif"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CONT_LIST">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_ContactList.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CHAT_ROOM">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_ChatRoom.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_TALK">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_Talk.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_CHATROOM_MENU">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\ChatRoom\\\\SB_CHAT.bmp"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_TALK_MENU">CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\ChatRoom\\\\SB_TALK.bmp"</IMAGE>

    <IMAGE id="IMG_ID_IMPS_USER_CONNECTED"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Connected.gif"</IMAGE>
    <IMAGE id="IMG_ID_IMPS_USER_DISCONNECTED"> CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Disconnect.gif"</IMAGE>
#endif /* __MMI_OP11_IMPS__ */

#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_OP11_IMPS__)  
    <IMAGE id = "IMG_ID_IMPS_TB_WRITE_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_Writemsg.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_WRITE_MSG_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_Writemsg_dis.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_SEND_FILE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_send_file.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_SEND_FILE_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_send_file_dis.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_CLOSE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_Close.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_EMOTION">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_emotion.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_EMOTION_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_emotion_dis.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_TEMPLATE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_templete.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_TEMPLATE_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_templete_dis.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_SEND">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_Send.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_SEND_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_Send_dis.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_INVITE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_invite.png"</IMAGE>
    <IMAGE id = "IMG_ID_IMPS_TB_INVITE_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\IMPS\\\\TB_invite_dis.png"</IMAGE>
#endif /* __MMI_ICON_BAR_SUPPORT__ */
    <!------------------------------------------------- Screen ID ----------------------------------------------------->

    <SCREEN id = "SCR_ID_IMPS_START"/>   
    <SCREEN id = "SCR_ID_IMPS_LOGO"/>
    <SCREEN id = "SCR_ID_IMPS_REGISTER"/>
    <SCREEN id = "SCR_ID_IMPS_HELP"/>
    <SCREEN id = "SCR_ID_IMPS_PROGRESS"/>
    <SCREEN id = "SCR_ID_IMPS_RECONN"/>
    <SCREEN id = "SCR_ID_IMPS_NETWORK_ROAMING_CONFIRM"/>
    <SCREEN id = "SCR_ID_IMPS_CHAT"/>
    <SCREEN id = "SCR_ID_IMPS_INSERT_SYMBOL"/>
    <SCREEN id = "SCR_ID_IMPS_USE_TEMPLATE"/>
    <SCREEN id = "SCR_ID_IMPS_CHAT_VIEW_IMAGE"/>
    <SCREEN id = "SCR_ID_IMPS_CHAT_VIEW_VIDEO"/>        
    <SCREEN id = "SCR_ID_IMPS_MM_MSG_ADD"/>
    <SCREEN id = "SCR_ID_IMPS_CHAT_CONFIRM_SEND"/>    
    <SCREEN id = "SCR_ID_IMPS_NOTIFY_MSG"/>    
    <SCREEN id = "SCR_ID_IMPS_CHAT_JOINED"/>    
    <SCREEN id = "SCR_ID_IMPS_CHAT_REJECTED"/>
    <SCREEN id = "SCR_ID_IMPS_CHAT_ROOM"/>
    <SCREEN id = "SCR_ID_IMPS_CHAT_ROOM_OPEN"/>        
    <SCREEN id = "SCR_ID_IMPS_CHAT_ROOM_JOIN"/>
    <SCREEN id = "SCR_ID_IMPS_INVITE"/>    
    <SCREEN id = "SCR_ID_IMPS_INVITE_EXT_CONV"/>        
    <SCREEN id = "SCR_ID_IMPS_INVITATION_IND"/>
    <SCREEN id = "SCR_ID_IMPS_SYSTEM_MESSAGE"/>
    <SCREEN id = "SCR_ID_IMPS_SYSTEM_MESSAGE_OPTION"/>
    <SCREEN id = "SCR_ID_IMPS_VERIFICATION_KEY"/>
    <SCREEN id = "SCR_ID_IMPS_SYSTEM_MSG_RES_CNF"/>
    <SCREEN id = "SCR_ID_IMPS_HTTP_AUTH"/>
    <SCREEN id = "SCR_ID_IMPS_OTA_SETTING"/>                   
    <SCREEN id = "SCR_ID_IMPS_CONT"/>        
    <SCREEN id = "SCR_ID_IMPS_ABOUT_ME"/>
    <SCREEN id = "SCR_ID_IMPS_PRESENCE_INLINE"/>
    <SCREEN id = "SCR_ID_IMPS_PRESENCE_VIEW_PIC"/>
    <SCREEN id = "SCR_ID_IMPS_ADD_CONT"/>
    <SCREEN id = "SCR_ID_IMPS_SEARCH_RESULT"/>
    <SCREEN id = "SCR_ID_IMPS_SELECT_GROUP"/>    
    <SCREEN id = "SCR_ID_IMPS_ABOUT_FRIEND"/>             
    <SCREEN id = "SCR_ID_IMPS_INVITE_PR_REMINDER"/>
    <SCREEN id = "SCR_ID_IMPS_ADD_CONT_SEL_GROUP"/>
    <SCREEN id = "SCR_ID_IMPS_EDIT_FNAME_AND_ALIAS_CONFIRM"/>
    <SCREEN id = "SCR_ID_IMPS_ROAMING"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_MY_PROF"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_CONNECT"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_NOTIFY"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_MS_NOTIFY"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_PR_NOTIFY"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_AUTO_LOGIN"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_AUTO_START"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_AUTHORIZE"/>
    <SCREEN id = "SCR_ID_IMPS_SETTING_LINK_PROF"/>  
    <SCREEN id = "SCR_ID_IMPS_COUNTRY_CODE"/>
    <SCREEN id = "SCR_ID_IMPS_VIEW_CONVERSATION"/>
    <SCREEN id = "SCR_ID_IMPS_VIEW_CONVERSATION_WAITING"/>
    <SCREEN id = "SCR_ID_IMPS_VIEW_CONVERSATION_JUMP"/>
    <SCREEN id = "SCR_ID_IMPS_VIEW_STRANGER_PP"/>
    /*
     * common version screen ID
     */
#ifndef __MMI_OP11_IMPS__
    <SCREEN id = "SCR_ID_IMPS_MAIN"/>
    <SCREEN id = "SCR_ID_IMPS_PROF"/>
    <SCREEN id = "SCR_ID_IMPS_OTA_PROF_LIST"/>
#endif /* #ifndef __MMI_OP11_IMPS__ */

    <SCREEN id = "SCR_ID_IMPS_END"/>

    <!--------------------------------------------- Screen Group ID --------------------------------------------------->
    
    <SCREEN id = "GRP_ID_IMPS"/>
    <SCREEN id = "GRP_ID_IMPS_OTA"/>
    <SCREEN id = "GRP_ID_IMPS_VIEW_CHAT_LOG"/>
    <SCREEN id = "GRP_ID_IMPS_MARKER"/>
    <SCREEN id = "GRP_ID_IMPS_CUI_ADD_CONT"/>
    <SCREEN id = "GRP_ID_IMPS_END"/>


    <!--------------------------------------------- Menu Resource Area ------------------------------------------------>
    /* setting  */
    <MENU id = "MENU_ID_IMPS_SETTING" type = "APP_SUB" str = "STR_GLOBAL_SETTINGS">
#ifndef __MMI_OP11_IMPS__
        <MENUITEM id = "MENU_ID_IMPS_PROF" str = "STR_GLOBAL_ACCOUNTS" />
#endif 
    	<MENUITEM id = "MENU_ID_IMPS_SETTING_MY_PROF" str = "STR_ID_IMPS_SETTING_MY_PROF" />
    	/* notify */
    	<MENU id = "MENU_ID_IMPS_SETTING_NOTIFY" type = "APP_SUB" str = "STR_ID_IMPS_SETTING_NOTIFY">
    	    <MENUITEM id = "MENU_ID_IMPS_SETTING_MS_NOTIFY" str = "STR_ID_IMPS_SETTING_MS_NOTIFY" />
    	    <MENUITEM id = "MENU_ID_IMPS_SETTING_PR_NOTIFY" str = "STR_ID_IMPS_SETTING_PR_NOTIFY" />
    	</MENU>
#ifdef __MMI_OP11_IMPS__    
        <MENUITEM id = "MENU_ID_IMPS_SETTING_CONNECT" str = "STR_ID_IMPS_SETTING_CONNECT" />
#endif    	
        <MENUITEM id = "MENU_ID_IMPS_SETTING_AUTO_LOGIN" str = "STR_ID_IMPS_SETTING_AUTO_LOGIN" />
#ifdef __MMI_OP11_IMPS__
        <MENUITEM id = "MENU_ID_IMPS_SETTING_AUTO_START" str = "STR_ID_IMPS_SETTING_AUTO_START" />
#endif        
    	<MENUITEM id = "MENU_ID_IMPS_SETTING_LINK_PROF" str = "STR_ID_IMPS_SETTING_LINK_PROF" />
    	<MENUITEM id = "MENU_ID_IMPS_SETTING_AUTHORIZE" str = "STR_ID_IMPS_SETTING_AUTHORIZE" />

        /* tone */
        <MENU id = "MENU_ID_IMPS_SETTING_TONE" type = "APP_SUB" str = "STR_ID_IMPS_SETTING_TONE">
            <MENUITEM id = "MENU_ID_IMPS_SETTING_CONTACT_ONLINE" str = "STR_ID_IMPS_SETTING_TONE_CONTACT_ONLINE" />
            <MENUITEM id = "MENU_ID_IMPS_SETTING_NEW_MESSAGE" str = "STR_ID_IMPS_SETTING_TONE_NEW_MESSAGE" />
            <MENUITEM id = "MENU_ID_IMPS_SETTING_NEW_INVITATION" str = "STR_ID_IMPS_SETTING_TONE_NEW_INVITATION" />
            <MENUITEM id = "MENU_ID_IMPS_SETTING_CHATROOM_NOTIFICATION" str = "STR_ID_IMPS_SETTING_TONE_CHATROOM_NOTIFICATION" />
        </MENU>
    </MENU>

#ifdef __MMI_OP11_IMPS__
    <MENU id = "MENU_ID_IMPS_MAIN" type = "APP_MAIN" str = "STR_ID_IMPS" img = "IMG_ID_IMPS_MENU"
        shortcut = "ON" shortcut_img = "IMG_ID_IMPS_MENU" launch = "mmi_imps_launch">
    </MENU>
#else /* __MMI_OP11_IMPS__ */
    <MENU id = "MENU_ID_IMPS_MAIN" type = "APP_MAIN" str = "STR_ID_IMPS" img = "IMG_ID_IMPS_MENU"
        shortcut = "ON" shortcut_img = "IMG_ID_IMPS_MENU" launch = "mmi_imps_launch">
        <MENUITEM id = "MENU_ID_IMPS_LOGIN" str = "STR_GLOBAL_LOGIN" />
        <MENUITEM_ID type="MENU"> MENU_ID_IMPS_SETTING </MENUITEM_ID>   
    </MENU>
#endif /* __MMI_OP11_IMPS__ */

#ifndef __MMI_OP11_IMPS__
 	<MENU id = "MENU_ID_IMPS_PROF_EDIT" type = "APP_SUB" str = "STR_GLOBAL_EDIT">
		<MENUITEM id = "MENU_ID_IMPS_PROF_SETTING" str = "STR_ID_IMPS_PROF_SETTING" />
        <MENUITEM id = "MENU_ID_IMPS_PROF_CONN" str = "STR_GLOBAL_DATA_ACCOUNT" />
	</MENU>

    <MENU id = "MENU_ID_IMPS_PROF_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_PROF_ACTIVATE" str = "STR_GLOBAL_ACTIVATE"/>
        <MENUITEM_ID type="MENU"> MENU_ID_IMPS_PROF_EDIT </MENUITEM_ID>
    </MENU>
#endif

    /* add contact */
 	<MENU id = "MENU_ID_IMPS_CONT_ADD" type = "APP_SUB" str = "STR_ID_IMPS_ADD_CONTACT">
		<MENUITEM id = "MENU_ID_IMPS_CONT_ADD_DIRECT" str = "STR_ID_IMPS_ADD_DIRECTLY" />
        <MENUITEM id = "MENU_ID_IMPS_SEARCH_DIRECT" str = "STR_ID_IMPS_SEARCH_BY_EMAIL" />
		<MENU id = "MENU_ID_IMPS_SEARCH_PHB" type = "APP_SUB" str = "STR_ID_IMPS_SEARCH_BY_NUMB">
            <MENUITEM id = "MENU_ID_IMPS_SEARCH_PHB_DIRECT" str = "STR_ID_IMPS_INPUT_NUM_DIRECT" />
            <MENUITEM id = "MENU_ID_IMPS_SEARCH_PHB_LOAD_ADDRESS" str = "STR_ID_IMPS_LOAD_NUM_FROM_ADDRESS" />
        </MENU>
	</MENU>

    /* contact list option */
    <MENU id = "MENU_ID_IMPS_CONT_LIST_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        /* fold unwrap list */
        <MENUITEM id = "MENU_ID_IMPS_CONT_LIST_FOLD_UNWRAP" str = "STR_ID_IMPS_FOLD_CONT_LIST" />
        /* about me */
        <MENU id = "MENU_ID_IMPS_CONT_ABOUT_ME" type = "OPTION" str = "STR_ID_IMPS_ABOUT_ME">
            <MENUITEM id = "MENU_ID_IMPS_CONT_PRESENCE" str = "STR_ID_IMPS_STATUS" />
            <MENUITEM id = "MENU_ID_IMPS_CONT_PUBLIC_PROFILE_1" str = "STR_ID_IMPS_PUBLIC_PROFILE_1" />
            <MENUITEM id = "MENU_ID_IMPS_CONT_PUBLIC_PROFILE_2" str = "STR_ID_IMPS_PUBLIC_PROFILE_2" />   
        </MENU>
        /* add contact or contact list */
        <MENU id = "MENU_ID_IMPS_ADD_CONT_GROUP" type = "OPTION" str = "STR_ID_IMPS_ADD_CONT_GROUP">
    		<MENUITEM_ID type="MENU"> MENU_ID_IMPS_CONT_ADD </MENUITEM_ID>
            <MENUITEM id = "MENU_ID_IMPS_GROUP_OPT_CREATE" str = "STR_ID_IMPS_CREATE_GROUP" />
        </MENU>
        /* manage contact list */
        <MENU id = "MENU_ID_IMPS_CONT_MANAGE_GROUP" type = "OPTION" str = "STR_ID_IMPS_MANAGE_GROUPS">
            <MENUITEM id = "MENU_ID_IMPS_GROUP_OPT_EDIT" str = "STR_GLOBAL_EDIT" />
            <MENUITEM id = "MENU_ID_IMPS_GROUP_OPT_DELETE" str = "STR_GLOBAL_DELETE" />
        </MENU>
        <MENUITEM id = "MENU_ID_IMPS_CONT_CHAT_ROOMS" str = "STR_ID_IMPS_CHAT_ROOMS" />
        <MENUITEM_ID type="MENU">MENU_ID_IMPS_SETTING</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_IMPS_CONT_LIST_REFRESH" str = "STR_ID_IMPS_CONT_LIST_REFRESH" />
#ifdef __MMI_OP11_IMPS__
    <MENUITEM id = "MENU_ID_IMPS_CONT_LIST_HELP" str = "STR_GLOBAL_HELP" />
#endif
        <MENUITEM id = "MENU_ID_IMPS_CONT_LOGOUT" str = "STR_ID_IMPS_LOGOUT" />
        <MENUITEM id = "MENU_ID_IMPS_CONT_EXIT" str = "STR_GLOBAL_EXIT" />
    </MENU>


    /* contact option */
    <MENU id = "MENU_ID_IMPS_CONT_USER_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_CONT_SEND_MSG" str = "STR_ID_IMPS_SEND_READ_MSG" />
        <MENUITEM_ID>MENU_ID_IMPS_CONT_LIST_FOLD_UNWRAP</MENUITEM_ID>
        <MENUITEM_ID type="MENU">MENU_ID_IMPS_CONT_ABOUT_ME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_ADD_CONT_GROUP</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_CONT_CHAT_ROOMS</MENUITEM_ID>
        /* manage contact */        
        <MENU id = "MENU_ID_IMPS_CONT_MANAGE" type = "OPTION" str = "STR_ID_IMPS_CONT_MANAGE">
            <MENUITEM id = "MENU_ID_IMPS_ABOUT_FRIEND_EDIT" str = "STR_ID_IMPS_CHANGE_NICK_NAME"/>
            <MENUITEM id = "MENU_ID_IMPS_ABOUT_FRIEND_REFRESH" str = "STR_ID_IMPS_VIEW_CONT_DETAIL"/>
            <MENUITEM id = "MENU_ID_IMPS_CONT_BLOCK_GRANT" str = "STR_ID_IMPS_BLOCK_CONTACT"/>
            <MENUITEM id = "MENU_ID_IMPS_CONT_MANAGE_MOVE" str = "STR_ID_IMPS_MOVE_CONTACT"/>
            <MENUITEM id = "MENU_ID_IMPS_CONT_DEL" str = "STR_ID_IMPS_DEL_CONTACT"/>
        </MENU>
        <MENUITEM id = "MENU_ID_IMPS_CONT_ABOUT_FRIEND" str = "STR_ID_IMPS_CONT_DETAILS" />
        <MENUITEM_ID type="MENU">MENU_ID_IMPS_SETTING</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_IMPS_CONT_LIST_REFRESH" str = "STR_ID_IMPS_CONT_LIST_REFRESH" />
        /* manage conversation */
        <MENU id = "MENU_ID_IMPS_CONT_MANAGE_CONVERSATION" type = "OPTION" str = "STR_ID_IMPS_MANAGE_CONVERSATION">
            <MENUITEM id = "MENU_ID_IMPS_CONT_VIEW_CONVERSATION" str = "STR_ID_IMPS_VIEW_CONVERSATION" />
            <MENUITEM id = "MENU_ID_IMPS_CONT_DEL_CONVERSATION" str = "STR_ID_IMPS_DEL_CONVERSATION" />
        </MENU>
#ifdef __MMI_OP11_IMPS__
        <MENUITEM id = "MENU_ID_IMPS_CONT_HELP" str = "STR_GLOBAL_HELP" />
#endif
        <MENUITEM_ID>MENU_ID_IMPS_CONT_LOGOUT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_CONT_EXIT</MENUITEM_ID>
    </MENU>

        
    /* presence file option */
    <MENU id = "MENU_ID_IMPS_PRESENCE_FILE_OPT" type = "OPTION" str = "STR_ID_IMPS_SEL_FILE">
        <MENUITEM id = "MENU_ID_IMPS_PRESENCE_FILE_OPT_VIEW" str = "STR_GLOBAL_VIEW"/>
        <MENUITEM id = "MENU_ID_IMPS_PRESENCE_FILE_OPT_SEL" str = "STR_ID_IMPS_SEL_FILE"/>
        <MENUITEM id = "MENU_ID_IMPS_PRESENCE_FILE_OPT_DEL" str = "STR_GLOBAL_DELETE"/>
    </MENU>    


    /* search contact option*/    
    <MENU id = "MENU_ID_IMPS_SEARCH_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_SEARCH_OPT_SEARCH" str = "STR_GLOBAL_SEARCH"/>
        <MENUITEM id = "MENU_ID_IMPS_SEARCH_OPT_QUIT" str = "STR_GLOBAL_QUIT"/>
    </MENU>


    /* stranger list option */
    <MENU id = "MENU_ID_IMPS_STRANGER_OPTION" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_STRANGER_OPT_GET_PP" str = "STR_ID_IMPS_VIEW_CONT_DETAIL"/>
        <MENUITEM id = "MENU_ID_IMPS_STRANGER_OPT_ADD" str = "STR_ID_IMPS_ADD_CONTACT"/>
    </MENU>


#ifdef __MMI_OP11_IMPS__
    /* login option */
    <MENU id = "MENU_ID_IMPS_LOGIN_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_LOGIN_OPT_GET_ACCT" str = "STR_ID_IMPS_GET_ACCT"/>
        <MENUITEM_ID type="MENU">MENU_ID_IMPS_SETTING</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_IMPS_LOGIN_OPT_HELP" str = "STR_GLOBAL_HELP"/>
        <MENUITEM id = "MENU_ID_IMPS_LOGIN_OPT_EXIT" str = "STR_GLOBAL_EXIT"/>
    </MENU>
#endif /* #ifdef __MMI_OP11_IMPS__ */


    /* register screen option */
    <MENU id = "MENU_ID_IMPS_REGISTER" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_USE_EXIST_ACCT" str = "STR_ID_IMPS_USE_EXIST_ACCT"/>
        <MENUITEM_ID>MENU_ID_IMPS_LOGIN_OPT_GET_ACCT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_LOGIN_OPT_EXIT</MENUITEM_ID>
    </MENU>

    
    /* chat option */
    <MENU id = "MENU_ID_IMPS_CHAT_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_WRITE" str = "STR_ID_IMPS_WRITE_MSG"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_CALL" str = "STR_GLOBAL_DIAL"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_SAVE_TO_PHB" str = "STR_GLOBAL_SAVE_TO_PHONEBOOK"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_GOTO" str = "STR_GLOBAL_GO_TO"/>
        /* send file */
        <MENU id = "MENU_ID_IMPS_CHAT_OPT_SEND_FILE" type = "OPTION" str = "STR_ID_IMPS_SEND_FILE">
            <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_SEND_FROM" str = "STR_ID_IMPS_SEL_FROM_FILE"/>
            <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_VOICE_MESSAGE" str = "STR_ID_IMPS_VOICE_MESSAGE"/>
            <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_PICTURE_MESSAGE" str = "STR_ID_IMPS_PICTURE_MESSAGE"/>
            <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_VIDEO_MESSAGE" str = "STR_ID_IMPS_VIDEO_MESSAGE"/>
        </MENU>

        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_INVITE" str = "STR_ID_IMPS_INVITE"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_LIST_JOINED" str = "STR_ID_IMPS_VIEW_PARTICIPANT"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_WITHDRAW_CONT" str = "STR_ID_IMPS_WITHDRAW_CONT"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_LIST_REJECTED" str = "STR_ID_IMPS_RECALL_USER"/>
#ifdef __MMI_OP11_IMPS__
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_HELP" str = "STR_GLOBAL_HELP"/>
#endif
        /* manage conversation */
        <MENU id = "MENU_ID_IMPS_MANAGE_CONVERSATION" type = "OPTION" str = "STR_ID_IMPS_MANAGE_CONVERSATION">
            <MENUITEM id = "MENU_ID_IMPS_SAVE_CONVERSATION" str = "STR_ID_IMPS_SAVE_CONVERSATION"/>
            <MENUITEM id = "MENU_ID_IMPS_VIEW_CONVERSATION" str = "STR_ID_IMPS_VIEW_CONVERSATION"/>
            <MENUITEM id = "MENU_ID_IMPS_DEL_CONVERSATION" str = "STR_ID_IMPS_DEL_CONVERSATION"/>
        </MENU>

        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_CLOSE" str = "STR_GLOBAL_CLOSE"/>
    </MENU>

    /* chat option 2 */
    <MENU id = "MENU_ID_IMPS_CHAT_OPT2" type = "OPTION" str = "STR_ID_IMPS_SEND_FILE">
        <MENUITEM_ID>MENU_ID_IMPS_CHAT_OPT_CALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_CHAT_OPT_SAVE_TO_PHB</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_CHAT_OPT_GOTO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_MANAGE_CONVERSATION</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_IMPS_CHAT_OPT_CLOSE</MENUITEM_ID>
    </MENU>    


    /* chat input option */
    <MENU id = "MENU_ID_IMPS_CHAT_INPUT_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_SEND" str = "STR_GLOBAL_SEND"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_INSERT_SYMBOL" str = "STR_ID_IMPS_INSERT_SYMBOL"/>
        <MENUITEM id = "MENU_ID_IMPS_CHAT_OPT_TEMPLATE" str = "STR_ID_IMPS_TEMPLATE"/>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>


    /* chat room option */
    <MENU id = "MENU_ID_IMPS_ROOM_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_ROOM_OPT_JUMP_TO" str = "STR_ID_IMPS_JUMP_TO"/>
        <MENUITEM id = "MENU_ID_IMPS_ROOM_OPT_CREATE" str = "STR_ID_IMPS_OPEN_CHAT_ROOM"/>
        <MENUITEM id = "MENU_ID_IMPS_ROOM_OPT_CLOSE" str = "STR_GLOBAL_CLOSE"/>
    </MENU>

    /* view conversation option */
    <MENU id = "MENU_ID_IMPS_VIEW_CONVERSATION_OPT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_IMPS_VIEW_CONVERSATION_OPT_NEXT" str = "STR_ID_IMPS_VIEW_CONVERSATION_NEXT"/>
        <MENUITEM id = "MENU_ID_IMPS_VIEW_CONVERSATION_OPT_PRE" str = "STR_ID_IMPS_VIEW_CONVERSATION_PRE"/>
        <MENUITEM id = "MENU_ID_IMPS_VIEW_CONVERSATION_OPT_JUMP" str = "STR_ID_IMPS_VIEW_CONVERSATION_JUMP"/>
    </MENU>


    <!---------------------------------------------- Timer Resource Area ---------------------------------------------->
    <TIMER id = "IMPS_LOGO_TIMER"/>
    <TIMER id = "IMPS_TAB_TIMER"/>
    <TIMER id = "IMPS_AUTO_START_WAIT_TIMER"/>
    <TIMER id = "IMPS_CHECK_PENDING_MSG_TIMER"/>
    
	<!----------------------------------------------- Other Resource -------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="mmi_imps_dt_acct_status_proc"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="mmi_imps_dt_acct_status_proc"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND" proc="mmi_imps_sim_preference_proc"/>
#ifdef __MMI_USB_SUPPORT__    
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_imps_usb_mass_storage_enter_proc"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_imps_usb_mass_storage_exit_proc"/>
#endif /*__MMI_USB_SUPPORT__*/
    
</APP>

#endif  /* __MMI_IMPS__ */
