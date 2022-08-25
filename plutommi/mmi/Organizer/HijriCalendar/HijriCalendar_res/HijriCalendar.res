/* Needed header files of the compile option in XML files, if you need others need to add here */

#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustomCfg.h"


#ifdef __MMI_HIJRI_CALENDAR__
#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif
#include "CustResDef.h"


#ifdef DEVELOPER_BUILD_FIRST_PASS

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_HIJRI_CALENDAR">

    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="CalendarResDef.h"/>
	<INCLUDE file="GlobalMenuItems.h"/>
	<INCLUDE file="Populateres.h"/>
     
	<!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String IDs for the application*/

    <STRING id="STR_HIJRI_DAY_DETAILS">"Day details"</STRING>
	<STRING id="STR_HIJRI_FESTIVALS">"Festivals"</STRING>
	<STRING id="STR_HIJRI_DATE_CORRECTION">"Date correction"</STRING>
	<STRING id="STR_HIJRI_DATE_SUB_TWO_DAYS">"-2"</STRING>
	<STRING id="STR_HIJRI_DATE_SUB_ONE_DAY">"-1"</STRING>
	<STRING id="STR_HIJRI_DATE_NO_CORRECTION">"No correction"</STRING>
	<STRING id="STR_HIJRI_DATE_ADD_ONE_DAY">"+1"</STRING>
	<STRING id="STR_HIJRI_DATE_ADD_TWO_DAYS">"+2"</STRING>
	<STRING id="STR_HIJRI_DATE">"Hijri date"</STRING>
	<STRING id="STR_HIJRI_SEND_AS_SMS">"As SMS"</STRING>
	<STRING id="STR_HIJRI_SEND_AS_MMS">"As MMS"</STRING>
	<STRING id="STR_HIJRI_SEND_AS_EMAIL">"As Email"</STRING>
	<STRING id="STR_HIJRI_FESTIVAL_DETAILS">"Festival details"</STRING>
	<STRING id="STR_HIJRI_ADD_REMINDER">"Add reminder"</STRING>
	<STRING id="STR_HIJRI_ANNO_HEGIRE">"A.H."</STRING>
	<STRING id="STR_HIJRI_ITWAAR">"Yaum al-ahad"</STRING>
	<STRING id="STR_HIJRI_PIR">"Yaum al-ithnayn"</STRING>
	<STRING id="STR_HIJRI_MANGAL">"Yaum ath-thulaathaa'"</STRING>
	<STRING id="STR_HIJRI_BUDH">"Yaum al-arbia`aa'"</STRING>
	<STRING id="STR_HIJRI_JUMAHRAAT">"Yaum al-khamis"</STRING>
	<STRING id="STR_HIJRI_JUMAH">"Yaum al-jumu`a"</STRING>
	<STRING id="STR_HIJRI_SANEECHAR">"Yaum as-sabt"</STRING>
	<STRING id="STR_HIJRI_MUHARRAM">"Muharram"</STRING>
	<STRING id="STR_HIJRI_SAFAR">"Safar"</STRING>
	<STRING id="STR_HIJRI_RABI_AWWAL">"Rabi' al-awwal"</STRING>
	<STRING id="STR_HIJRI_RABI_THANI">"Rabi' al-thani"</STRING>
	<STRING id="STR_HIJRI_JUMADA_AWWAL">"Jumada al-awwal"</STRING>
	<STRING id="STR_HIJRI_JUMADA_THANI">"Jumada al-thani"</STRING>
	<STRING id="STR_HIJRI_RAJAB">"Rajab"</STRING>
	<STRING id="STR_HIJRI_SHAABAN">"Sha'aban"</STRING>
	<STRING id="STR_HIJRI_RAMADAN">"Ramadan"</STRING>
	<STRING id="STR_HIJRI_SHAWAL">"Shawwal"</STRING>
	<STRING id="STR_HIJRI_DHU_QIDDAH">"Dhu al-Qi'dah"</STRING>
	<STRING id="STR_HIJRI_DHU_HIJJAH">"Dhu al-Hijjah"</STRING>
	<STRING id="STR_HIJRI_NEW_YEAR">"Islamic new year"</STRING>
	<STRING id="STR_HIJRI_DAY_OF_ASHURAH">"Day of Ashurah"</STRING>
	<STRING id="STR_HIJRI_RABI_AWAL_SUNNI">"Mawlid an Nabi (Sunni)"</STRING>
	<STRING id="STR_HIJRI_RABI_AWAL_SHIA">"Mawlid an Nabi (Shia)"</STRING>
	<STRING id="STR_HIJRI_BDAY_ALI_IBN">"Ali ibn Abi Talib b'day"</STRING>
	<STRING id="STR_HIJRI_ISRA_MIRAI">"Isra and Miraj"</STRING>
	<STRING id="STR_HIJRI_SHAB_E_BARAAT">"Shab-e-Baraat"</STRING>
	<STRING id="STR_HIJRI_FIRST_RAMADAN">"First Ramadan"</STRING>
	<STRING id="STR_HIJRI_NAZUL_QURAN">"Nuzul Al-Qur'an"</STRING>
	<STRING id="STR_HIJRI_EID_AL_FITR">"Eid al-Fitr"</STRING>
	<STRING id="STR_HIJRI_DHUA_AL_HIJJAH">"Hajj to Mecca"</STRING>
	<STRING id="STR_HIJRI_EID_AL_GADHA">"Eid al-Adha"</STRING>
	<STRING id="STR_HIJRI_EID_AL_GADHIR">"Eid al-Gadheer"</STRING>
	<STRING id="STR_HIJRI_NEW_YEAR_DETAIL">"The beginning of the Islamic new year."</STRING>
	<STRING id="STR_HIJRI_DAY_OF_ASHURAH_DETAIL">"In the early days of Islam, the fasting on the 10th of Ashurah was treated as compulsory. The Holy Prophet preferred the fast of Ashurah to the fast of other days, and the fast of Ramadan to the fast of Ashurah. The fasting on the day of Ashurah is the Sunnah of Holy Prophet and makes one entitled to great reward."</STRING>
	<STRING id="STR_HIJRI_RABI_AWAL_SUNNI_DETAIL">"The birth date of Muhammad, the creator of Islam. Mawlid means birthday of a holy figure and al-Nabi means prophet. The day is commemorated with recollections of Muhammad's life and significance."</STRING>
	<STRING id="STR_HIJRI_RABI_AWAL_SHIA_DETAIL">"The birth date of Muhammad, the creator of Islam. Mawlid means birthday of a holy figure and al-Nabi means prophet. The day is commemorated with recollections of Muhammad's life and significance."</STRING>
	<STRING id="STR_HIJRI_BDAY_ALI_IBN_DETAIL">"Ali is respected for his knowledge, belief, honesty, unbending devotion to Islam, deep loyalty to Muhammad, equal treatment of all Muslims and generosity in forgiving his defeated enemies, and therefore is central to mystical traditions in Islam such as Sufism."</STRING>
	<STRING id="STR_HIJRI_ISRA_MIRAI_DETAIL">"Isra refers to the journey of Muhammad from Mecca to a distant mosque in Jerusalem on the back of a heavenly creature called al-buraq. From there he began his journey to the heaven(Miraj) where the Allah gave the orders of 5 times prayer a day, and back to Mecca on the same night. There are no celebrations by Muslims, only the story of Miraj is told to the children via poetry, chants or lectures. Sweets and food are distributed in a festive atmosphere."</STRING>
	<STRING id="STR_HIJRI_SHAB_E_BARAAT_DETAIL">"When the night of the middle of the Shabaan comes, the Muslims spend the night in prayers and fast the next day so that the Allah forgive their sins."</STRING>
	<STRING id="STR_HIJRI_FIRST_RAMADAN_DETAIL">"The first day of the month of the Ramadan. During the blessed month of Ramadan, Muslims all over the world abstain from food, drink, and other physical needs during the daylight hours. As a time to purify the soul, refocus attention on God, and practice self-sacrifice, Ramadan is much more than just not eating and drinking."</STRING>
	<STRING id="STR_HIJRI_NAZUL_QURAN_DETAIL">"Nuzul Al-Qur'an or the commemoration of the revelation of the Holy Quran is one of the highlights of the holy month of Islam. It refers to the revelation of the first verses of the Holy Quran to Prophet Muhammad. The event is meant to teach Muslims to be appreciative and be humbled by the magnificence of the miracle and to take its teachings to heart and to follow its examples in the efforts to lead their lives accordingly."</STRING>
	<STRING id="STR_HIJRI_EID_AL_FITR_DETAIL">"At the end of Ramadan, Muslims throughout the world observe a joyous three-day celebration called Eid al-Fitr (the festival of Fast-Breaking). It is a time to give in charity to those in need, and celebrate with families and friends the completion of a month of blessings and joy. On the day of Eid, Muslims gather early in the morning in outdoor locations or mosques to perform the Eid prayer. After the Eid prayer, Muslims usually scatter to visit various families and friends and give gifts."</STRING>
	<STRING id="STR_HIJRI_DHUA_AL_HIJJAH_DETAIL">"The Hajj to Mecca must be carried out at least once in their lifetime by every able-bodied Muslim. As part of the Hajj, each person walks counter-clockwise seven times around the Kaaba, the cube-shaped building which acts as the Muslim direction of prayer (qibla); runs back and forth between the hills of Al-Safa and Al-Marwah; drinks from the Zamzam Well; goes to the plains of Mount Arafat to stand in vigil; and throws stones in a ritual Stoning of the Devil."</STRING>
	<STRING id="STR_HIJRI_EID_AL_GADHA_DETAIL">"During the celebration of Eid al-Adha, Muslims commemorate and remember Abraham's trials (he was to kill his own son for Allah), by themselves slaughtering an animal such as a sheep, camel, or goat. One-third of the meat from the sacrifice of Eid al-Adha is eaten by immediate family and relatives, one-third is given away to friends, and one-third is donated to the poor."</STRING>
	<STRING id="STR_HIJRI_EID_AL_GADHIR_DETAIL">"A celebration held on the 18th of Dhu al-Hijjah marking the event of Ghadeer Khumm in 10 AH. The day on which God stated the completion of Islam. It is an event celebrated by Shias (and not by Sunni Muslims), and is the basis of their confirmation of Ali ibn Abi Talib's succession to Muhammad."</STRING>
	<STRING id="STR_HIJRI_RABI_ONE">"Rabi I"</STRING>
	<STRING id="STR_HIJRI_RABI_TWO">"Rabi II"</STRING>
	<STRING id="STR_HIJRI_JUMADA_ONE">"Jumada I"</STRING>
	<STRING id="STR_HIJRI_JUMADA_TWO">"Jumada II"</STRING>
	<STRING id="STR_HIJRI_DAY">"Day:"</STRING>
	<STRING id="STR_HIJRI_MONTH">"Month:"</STRING>
	<STRING id="STR_HIJRI_DATE">"Date:"</STRING>
	<STRING id="STR_HIJRI_YEAR">"Year:"</STRING>
	<STRING id="STR_HIJRI_FESTIVAL">"Festival:"</STRING>
	<STRING id="STR_HIJRI_FESTIVAL_LIST">"Festival list"</STRING>
	<STRING id="STR_HIJRI_SEND_HIJRI_DATE">"Send hijri date"</STRING>
	<STRING id="STR_HIJRI_HIJRI_DATE">"Hijri date"</STRING>
	<STRING id="STR_HIJRI_GO_TO_CALENDAR">"Go to calendar"</STRING>
	<STRING id="STR_HIJRI_DOW_SUNDAY">"Sunday"</STRING>
	<STRING id="STR_HIJRI_DOW_MONDAY">"Monday"</STRING>
	<STRING id="STR_HIJRI_DOW_TUESDAY">"Tuesday"</STRING>
	<STRING id="STR_HIJRI_DOW_WEDNESDAY">"Wednesday"</STRING>
	<STRING id="STR_HIJRI_DOW_THURSDAY">"Thursday"</STRING>
	<STRING id="STR_HIJRI_DOW_FRIDAY">"Friday"</STRING>
	<STRING id="STR_HIJRI_DOW_SATURDAY">"Saturday"</STRING>
	<STRING id="STR_HIJRI_DESCRIPTION">"Description:"</STRING>
	<STRING id="STR_HIJRI_ABC">"ABC"</STRING>
	<STRING id="STR_HIJRI_CALENDAR_HELP">"(1) Hijri calendar is based on arithmetic calendar which assigns 30 and 29 days for alternate months. Support is present from Gregorian year 2000 to 2030 only.\n(2) Use date correction to adjust hijri date with moon crescent.\n(3) Use star key (*) to switch between calendars.\n(4) Use left and right navigation keys to view details of previous and next festival in festival details screen.\n(5) Use left and right navigation keys to view hijri date of previous and next date in hijri date details."</STRING>
    <STRING id="STR_HIJRI_VALID_RANGE">"Valid date is 2000~2030"</STRING>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
 
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <IMAGE id="IMG_ID_HIJRI_FESTIVAL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\HijriFestival.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
        

    <MENUITEM id="MENU_ID_HIJRI_GO_TO_CALENDAR_DAY_DETAILS" str="STR_HIJRI_GO_TO_CALENDAR" highlight="mmi_hijri_highlight_go_to_calendar_day_details"/>
	<MENUITEM id="MENU_ID_HIJRI_ADD_REMINDER_DAY_DETAILS" str="STR_HIJRI_ADD_REMINDER" highlight="mmi_hijri_highlight_add_reminder_day_details"/>


   //<MENU id="MENU_ID_HIJRI_DAY_DETAILS_OPTIONS" type="OPTION" parent="0" str="STR_GLOBAL_OPTIONS"/>
   /*This menu item has no parent, take care of this*/

    <MENU id="MENU_ID_HIJRI_SEND_DATE" str="STR_HIJRI_SEND_HIJRI_DATE" highlight="mmi_hijri_highlight_send_date">
       <MENUITEM id="MENU_ID_HIJRI_SEND_DATE_BY_SMS" str="STR_GLOBAL_AS_TEXT_MESSAGE" highlight="mmi_hijri_highlight_send_by_SMS"/>

       #ifdef __MMI_MMS__
           <MENUITEM id="MENU_ID_HIJRI_SEND_DATE_BY_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG" highlight="mmi_hijri_highlight_send_by_MMS"/>
       #endif

	   #ifdef __MMI_EMAIL__
	       <MENUITEM id="MENU_ID_HIJRI_SEND_DATE_BY_EMAIL" str="STR_GLOBAL_AS_EMAIL" highlight="mmi_hijri_highlight_send_by_EMAIL"/>
       #endif
    </MENU>


   <MENU id="MENU_ID_HIJRI_DAY_DETAILS_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_HIJRI_GO_TO_CALENDAR_DAY_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_HIJRI_ADD_REMINDER_DAY_DETAILS</MENUITEM_ID> 
        <MENUITEM_ID>MENU_ID_HIJRI_SEND_DATE</MENUITEM_ID> 
   </MENU>


	<MENU id="MENU_ID_HIJRI_DATE_CORRECTION" str="STR_HIJRI_DATE_CORRECTION" highlight="mmi_hijri_highlight_date_correction" hint="mmi_hijri_date_correction_set_hilite_index">
		<MENUITEM id="MENU_ID_HIJRI_DATE_SUB_TWO_DAYS"  str="STR_HIJRI_DATE_SUB_TWO_DAYS"/>
	    <MENUITEM id="MENU_ID_HIJRI_DATE_SUB_ONE_DAY" str="STR_HIJRI_DATE_SUB_ONE_DAY"/>
	    <MENUITEM id="MENU_ID_HIJRI_DATE_NO_CORRECTION" str="STR_HIJRI_DATE_NO_CORRECTION"/>
	    <MENUITEM id="MENU_ID_HIJRI_DATE_ADD_ONE_DAY" str="STR_HIJRI_DATE_ADD_ONE_DAY"/>		
	    <MENUITEM id="MENU_ID_HIJRI_DATE_ADD_TWO_DAYS" str="STR_HIJRI_DATE_ADD_TWO_DAYS"/>
	</MENU>
	
    <MENU id="MENU_ID_HIJRI_FESTIVALS" str="STR_HIJRI_FESTIVAL_LIST" highlight="mmi_hijri_highlight_hijri_festivals">
    </MENU>
    
    <MENU id="MENU_ID_HIJRI_DAY_DETAILS" str="STR_HIJRI_HIJRI_DATE" highlight="mmi_hijri_highlight_day_details">
    </MENU>
    /*One children menu item left in res_organizer.c*/

    /*<MENU id="ORGANIZER_CALENDER_MONTHLY_OPTIONS_MENU" type="OPTION" str="ORGANIZER_MENU_CALENDER_STRINGID">
        <MENUITEM_ID>MENU_ID_HIJRI_FESTIVALS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_HIJRI_DATE_CORRECTION</MENUITEM_ID> 
        <MENUITEM_ID>MENU_ID_HIJRI_DAY_DETAILS</MENUITEM_ID> 
    </MENU>*/

    <MENUITEM id="MENU_ID_HIJRI_GO_TO_CALENDAR_FESTIVALS" str="STR_HIJRI_GO_TO_CALENDAR" highlight="mmi_hijri_highlight_go_to_calendar_festivals"/>
	<MENUITEM id="MENU_ID_HIJRI_ADD_REMINDER_FESTIVALS" str="STR_HIJRI_ADD_REMINDER" highlight="mmi_hijri_highlight_add_reminder_for_festivals"/>


     /*no parent for the menu id - MENU_ID_HIJRI_FESTIVAL_OPTIONS*/ 
     <MENU id="MENU_ID_HIJRI_FESTIVAL_OPTIONS" type="OPTION" str="STR_HIJRI_FESTIVAL_DETAILS" highlight="mmi_hijri_highlight_festival_options">
        <MENUITEM_ID>MENU_ID_HIJRI_GO_TO_CALENDAR_FESTIVALS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_HIJRI_ADD_REMINDER_FESTIVALS</MENUITEM_ID> 
     </MENU>

     <CACHEDATA type="byte" id="NVRAM_HIJRI_CORRECTION">
        <DEFAULT_VALUE> [0x02] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
     
<!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->	     

	<SCREEN id="SCR_ID_HIJRI_MAIN_MENU"/>
	<SCREEN id="SCR_ID_HIJRI_DAY_DETAILS"/>
	<SCREEN id="SCR_ID_HIJRI_DATE_CORRECTION"/>
	<SCREEN id="SCR_ID_HIJRI_SEND_HIJRI_DATE"/>
	<SCREEN id="SCR_ID_HIJRI_FESTIVAL_LIST"/>
	<SCREEN id="SCR_ID_HIJRI_FESTIVAL_OPTION"/>
	<SCREEN id="SCR_ID_HIJRI_FESTIVAL_DETAILS"/>
	<SCREEN id="SCR_ID_HIJRI_FESTIVAL_UPCOMING_OCCURENCE"/>
	<SCREEN id="SCR_ID_HIJRI_JUMP_TO_YEAR"/>
	<SCREEN id="SCR_ID_HIJRI_DAY_DETAILS_OPTIONS"/>
	
        <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
<!--------------------------------------------------------------------------------------------------------------------->     
</APP>

#endif /* DEVELOPER_BUILD_FIRST_PASS */
#endif /* __MMI_HIJRI_CALENDAR__ */
