/* add if you use any compile options defined in MMI_features.h */

#include "MMI_features.h"
#ifdef __MMI_INDICAL__
#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "GlobalDefs.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_INDICAL">

    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="CalendarResDef.h"/>
	<INCLUDE file="GlobalMenuItems.h"/>

	<!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String IDs for the application*/


    <STRING id="STR_INDICAL_INDIAN_CALENDAR">"Panchangam"</STRING>
	<STRING id="STR_INDICAL_FESTIVALS">"Festival list"</STRING>
	<STRING id="STR_INDICAL_SEND_TITHI">"Send panchangam"</STRING>
	<STRING id="STR_INDICAL_ADD_REMINDER">"Add reminder"</STRING>
	<STRING id="STR_INDICAL_RAVIWARA">"Raviwara"</STRING>
	<STRING id="STR_INDICAL_SOMAVARA">"Somvara"</STRING>
	<STRING id="STR_INDICAL_MANGALVARA">"Mangalwara"</STRING>
	<STRING id="STR_INDICAL_BUDHAVARA">"Budhawara"</STRING>
	<STRING id="STR_INDICAL_GURUVARA">"Guruwara"</STRING>
	<STRING id="STR_INDICAL_SUKRAVARA">"Shukrwara"</STRING>
	<STRING id="STR_INDICAL_SANIVARA">"Shaniwara"</STRING>
	<STRING id="STR_INDICAL_CHAITRA">"Chaitra"</STRING>
	<STRING id="STR_INDICAL_VAISAKHA">"Vaisakha"</STRING>
	<STRING id="STR_INDICAL_JYAISTHA">"Jyaistha"</STRING>
	<STRING id="STR_INDICAL_ASADHA">"Asadha"</STRING>
	<STRING id="STR_INDICAL_SRAVANA">"Sravana"</STRING>
	<STRING id="STR_INDICAL_BHADRAPADA">"Bhadrapada"</STRING>
	<STRING id="STR_INDICAL_ASVINA">"Asvina"</STRING>
	<STRING id="STR_INDICAL_KARTTIKA">"Karttika"</STRING>
	<STRING id="STR_INDICAL_MARGASIRSA">"Margasirsa"</STRING>
	<STRING id="STR_INDICAL_PAUSA">"Pausa"</STRING>
	<STRING id="STR_INDICAL_MAGHA">"Magha"</STRING>
	<STRING id="STR_INDICAL_PHALGUNA">"Phalguna"</STRING>
	<STRING id="STR_INDICAL_PRATHMA">"Prathma"</STRING>
	<STRING id="STR_INDICAL_DVITIYA">"Dwitiya"</STRING>
	<STRING id="STR_INDICAL_SHORT_PRATHMA">"P."</STRING>
	<STRING id="STR_INDICAL_SHORT_DWITIYA">"D."</STRING>
	<STRING id="STR_INDICAL_KRISHANA_PAKSHA">"Krishana Paksha"</STRING>
	<STRING id="STR_INDICAL_SHUKLA_PAKSHA">"Shukla Paksha"</STRING>
	<STRING id="STR_INDICAL_SHORT_KRISHANA_PAKSHA">"K. Paksha"</STRING>
	<STRING id="STR_INDICAL_SHORT_SHUKLA_PAKSHA">"S. Paksha"</STRING>
	<STRING id="STR_INDICAL_EKAM">"Ekam"</STRING>
	<STRING id="STR_INDICAL_DWITIYA">"Dwitiya"</STRING>
	<STRING id="STR_INDICAL_TRITIYA">"Tritiya"</STRING>
	<STRING id="STR_INDICAL_CHATURTHI">"Chaturthi"</STRING>
	<STRING id="STR_INDICAL_PANCHAMI">"Panchami"</STRING>
	<STRING id="STR_INDICAL_SASTHI">"Shasthi"</STRING>
	<STRING id="STR_INDICAL_SAPTAMI">"Saptami"</STRING>
	<STRING id="STR_INDICAL_ASTHAMI">"Ashtami"</STRING>
	<STRING id="STR_INDICAL_NAVMI">"Navmi"</STRING>
	<STRING id="STR_INDICAL_DASHMI">"Dashami"</STRING>
	<STRING id="STR_INDICAL_EKADASHI">"Ekadashi"</STRING>
	<STRING id="STR_INDICAL_DWADASHI">"Dwadashi"</STRING>
	<STRING id="STR_INDICAL_TRAYODASHI">"Trayodashi"</STRING>
	<STRING id="STR_INDICAL_CHATURDASHI">"Chaturdashi"</STRING>
	<STRING id="STR_INDICAL_PURANMASI">"Puranmasi"</STRING>
	<STRING id="STR_INDICAL_AMAVASYA">"Amavasya"</STRING>
	<STRING id="STR_INDICAL_GURU_GOVIND_SINGH_JAYANTI">"Guru Govind Singh Jayanti"</STRING>
	<STRING id="STR_INDICAL_LOHRI">"Lohri"</STRING>
	<STRING id="STR_INDICAL_MAKAR_SAKRANTI">"Makar Sakranti"</STRING>
	<STRING id="STR_INDICAL_BAISHAKHI">"Baisakhi"</STRING>
	<STRING id="STR_INDICAL_BASANT_PANCHMI">"Basant Panchmi"</STRING>
	<STRING id="STR_INDICAL_MAHASHIV_RATRI">"Mahashiv Ratri"</STRING>
	<STRING id="STR_INDICAL_HOLIKA_DEHAN">"Holika Dahan"</STRING>
	<STRING id="STR_INDICAL_HOLI">"Holi"</STRING>
	<STRING id="STR_INDICAL_NAV_VARSHA">"Nav Varsha"</STRING>
	<STRING id="STR_INDICAL_RAM_NAVMI">"Ram Navmi"</STRING>
	<STRING id="STR_INDICAL_RAKSHA_BANDHAN">"Raksha Bandhan"</STRING>
	<STRING id="STR_INDICAL_JANMASTMI">"Janmashtami"</STRING>
	<STRING id="STR_INDICAL_GANESH_CHATURTHI">"Ganesh Chaturthi"</STRING>
	<STRING id="STR_INDICAL_NAWMI">"Maha Navmi"</STRING>
	<STRING id="STR_INDICAL_DASHEHRA">"Dashehra"</STRING>
	<STRING id="STR_INDICAL_DEEPAWALI">"Deepawali"</STRING>
	<STRING id="STR_INDICAL_VIKRAMI">"Vikrami"</STRING>
	<STRING id="STR_INDICAL_VALID_RANGE">"Valid date is 2000~2030"</STRING>
	<STRING id="STR_INDICAL_GURU_GOVIND_SINGH_JAYANTI_DETAILS">"The birthday of Guru Gobind Singh ji, who played a monumental part in the development of the Sikh faith. He created a warrior brotherhood that evolve Sikhism as a disciplined and determined religion."</STRING>
	<STRING id="STR_INDICAL_LOHRI_DETAILS">"Lohri marks the culmination of winter. People gather round the bonfires, throw sweets, puffed rice and popcorn into the flames, sing popular songs and exchange greetings."</STRING>
	<STRING id="STR_INDICAL_MAKAR_SAKRANTI_DETAILS">"This festival is celebrated by taking dips in the Ganga or any river and offering water to the Sun god. The dip is said to purify the self and bestow punya. Special puja is offered as a thanksgiving for good harvest."</STRING>
	<STRING id="STR_INDICAL_BASANT_PANCHMI_DETAILS">"This is a festival celebrating Saraswati, the Goddess of knowledge, music and art. During this festival children are taught their first words and brahmins are fed."</STRING>
	<STRING id="STR_INDICAL_MAHASHIV_RATRI_DETAILS">"Mahashiv Ratri is celebrated on the 6th night of the dark Phalgun every year. It is believed that on this day Lord Shiva was married to Devi Parvati. On this auspicious day, devotees observe fast, keep vigil all night and offer fruits, flowers and bel leaves on Shiva Linga."</STRING>
	<STRING id="STR_INDICAL_HOLIKA_DEHAN_DETAILS">"This festival takes place on the eve of Holi. The day is also popularly called 'Chhoti Holi' or the 'Small Holi'. The bigger event of playing with the colour takes place on the next day."</STRING>
	<STRING id="STR_INDICAL_HOLI_DETAILS">"This is a popular spring festival, observed in India, also called the Festival of Colours. People spend the day throwing coloured powder and water at each other."</STRING>
	<STRING id="STR_INDICAL_NAV_VARSHA_DETAILS">"Indian calendar new year beginning."</STRING>
	<STRING id="STR_INDICAL_BAISHAKHI_DETAILS">"Baisakhi is a long established harvest festival in Punjab that also has religious significance. Baisakhi is one of the holiest days in Sikhism, commemorating Khalsa."</STRING>
	<STRING id="STR_INDICAL_RAKSHA_BANDHAN_DETAILS">"It celebrates the love of a brother for his sister. On this day, sisters tie Rakhi on the wrists of their brothers to protect them against evil influences."</STRING>
	<STRING id="STR_INDICAL_JANMASTMI_DETAILS">"Lord Vishnu is invoked in his human incarnation as Krishna on his birth anniversary. The temples of Vrindavan witness a colourful celebration on this occasion."</STRING>
	<STRING id="STR_INDICAL_NAWMI_DETAILS">"The culmination of the Navratra festival is Maha Navmi when the goddess Durga is worshipped as Aparajita. This is the concluding day of Durga Puja. The main Navmi puja begins after the end of Sandhi Puja. The Navmi Bhog is offered to the goddess. This is later partaken as prasad by the devotees."</STRING>
	<STRING id="STR_INDICAL_DASHEHRA_DETAILS">"The famous festival of Dashehra or Vijaya Dashami comes after the nine days of Navaratra. On this day Lord Rama had killed Ravana, signifying the victory of good over evil. Massive effigies of Ravana, his younger brother Kumbhakarna and son Meghanatha are erected, stuffed with fire-crackers and set aflame."</STRING>
	<STRING id="STR_INDICAL_DEEPAWALI_DETAILS">"Twinkling oil lamps or diyas light up every home and firework displays are common all across the country. Crackers and fireworks illuminate the sky and people pray for a prosperous coming year."</STRING>
	<STRING id="STR_INDICAL_RAM_NAVMI_DETAILS">"Ram Navami falls on the ninth day of the Hindu lunar year and celebrated as the birthday of Shree Ram. Lord Ram was the seventh incarnation of Lord Vishnu, who takes birth on earth when Adharma over rules Dharma. Lord Ram was born on earth to destroy the demon named Ravan. On this day, Hindus do fast or restrict themselves to a specific diet and perform worship. Temples are decorated and readings of the Ramayana take place. Along with Shri Ram, people also worship Sita mata, wife of Shree Ram."</STRING>
	<STRING id="STR_INDICAL_GANESH_CHATURTHI_DETAILS">"Ganesh Chaturthi is a day on which Lord Ganesha, the son of Shiva and Parvati, is believed to bestow his presence on earth for all his devotees. The festival lasts for 10 days, ending on Ananta Chaturdashi. Ganesha, the elephant-headed son of Shiva and Parvati, is widely worshipped as the supreme god of wisdom, prosperity and good fortune."</STRING>
	<STRING id="STR_INDICAL_INFO">"Tithi list"</STRING>
	<STRING id="STR_INDICAL_PAKSHA">"Paksha:"</STRING>
	<STRING id="STR_INDICAL_GOTO_CALENDAR">"Go to calendar"</STRING>
	<STRING id="STR_INDICAL_DAY">"Day:"</STRING>
	<STRING id="STR_INDICAL_DATE">"Date:"</STRING>
	<STRING id="STR_INDICAL_YEAR">"Year:"</STRING>
	<STRING id="STR_INDICAL_MONTH">"Month:"</STRING>
	<STRING id="STR_INDICAL_FESTIVAL">"Festival:"</STRING>
	<STRING id="STR_INDICAL_TITHI">"Tithi:"</STRING>
	<STRING id="STR_INDICAL_SUNDAY">"Sunday"</STRING>
	<STRING id="STR_INDICAL_MONDAY">"Monday"</STRING>
	<STRING id="STR_INDICAL_TUESDAY">"Tuesday"</STRING>
	<STRING id="STR_INDICAL_WEDNESDAY">"Wednesday"</STRING>
	<STRING id="STR_INDICAL_THURSDAY">"Thursday"</STRING>
	<STRING id="STR_INDICAL_FRIDAY">"Friday"</STRING>
	<STRING id="STR_INDICAL_SATURDAY">"Saturday"</STRING>
	<STRING id="STR_INDICAL_DESCRIPTION">"Description:"</STRING>
	<STRING id="STR_INDICAL_HELP">"(1) Hindu calendar is based on Purnimanta calendar. Support is present from Gregorian year 2000 to 2030 only.\n(2) Popup displays the panchangam of the selected day on main screen.\n(3) Use star key (*) to switch between calendars.\n(4) Use Left and right navigation keys to view details of previous and next festival in festival details screen.\n(5) Use Left and right navigation keys to view panchangam of previous and next date in panchangam details screen."</STRING>

     <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */



    <IMAGE id="IMG_ID_FESTIVAL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\IndianFestival.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PURANMAASI">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\Purnima.bmp"</IMAGE>
    <IMAGE id="IMG_ID_AMAVASYA">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\Amavasya.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */


    /*Check this menu id for parent menu id and highlight handler as this is the entry point for the applicatiohn*/
    /*<MENU id="ORGANIZER_CALENDER_MENU" type="OPTION" str="ORGANIZER_MENU_CALENDER_STRINGID" img="ORGANIZER_MENU_CALENDER_IMAGEID" highlight="HighlightClndrMenu">*/
        <MENU id="MENU_ID_INDICAL_TITHI" str="STR_INDICAL_INDIAN_CALENDAR" highlight="HighlightIndiCalTithiMenu">
        </MENU>          
		<MENU id="MENU_ID_INDICAL_FESTIVAL_LIST" str="STR_INDICAL_FESTIVALS" highlight="HighlightIndiCalFestivalListMenu">
		
    </MENU>


    <MENU id="MENU_ID_INDICAL_SEND_TITHI" str="STR_INDICAL_SEND_TITHI" highlight="HighlightIndiCalSendTithi">		
		<MENUITEM id="MENU_ID_INDICAL_ADD_SMS_NO" str="STR_GLOBAL_AS_TEXT_MESSAGE" highlight="HighlightIndiCalSendTithiAsSMS"/>

		#ifdef __MMI_MMS__
		    <MENUITEM id="MENU_ID_INDICAL_ADD_MMS_NO" str="STR_GLOBAL_AS_MULTIMEDIA_MSG" highlight="HighlightIndiCalSendTithiAsMMS"/>
        #endif

        #ifdef __MMI_EMAIL__
		<MENUITEM id="MENU_ID_INDICAL_ADD_EMAIL_ID" str="STR_GLOBAL_AS_EMAIL" highlight="HighlightIndiCalSendTithiAsEMAIL"/>
        #endif
	</MENU>

		
     <MENU id="MENU_ID_INDICAL_TITHI_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">        

		<MENUITEM id="MENU_ID_INDICAL_GOTO_CALENDAR_TITHI" str="STR_INDICAL_GOTO_CALENDAR" highlight="HighlightIndiCalGoToCalendartTithi"/>
		#ifdef __MMI_TODOLIST__
        <MENUITEM id="MENU_ID_INDICAL_ADD_REMINDER" str="STR_INDICAL_ADD_REMINDER" highlight="HighlightIndiCalTithiReminder"/>
        #endif
        <MENUITEM_ID>MENU_ID_INDICAL_SEND_TITHI</MENUITEM_ID>                      
     </MENU>	

    <MENU id="MENU_ID_INDICAL_FESTIVAL_OPTION" type="OPTION" str="STR_INDICAL_FESTIVALS">        

		<MENUITEM id="MENU_ID_INDICAL_GOTO_CALENDAR_FESTIVAL" str="STR_INDICAL_GOTO_CALENDAR" highlight="HighlightIndiCalGoToCalendarFestival"/>
         
        #ifdef __MMI_TODOLIST__ 
		<MENUITEM id="MENU_ID_INDICAL_ADD_FESTIVAL_REMINDER" str="STR_INDICAL_ADD_REMINDER" highlight="HighlightIndiCalFestivalReminder"/>   
        #endif   
	</MENU>
	
<!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->	     

	<SCREEN id="SCR_ID_INDICAL_MAIN_MENU"/>
	<SCREEN id="SCR_ID_INDICAL_TITHI_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_TITHI_OPTION_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_TITHI_NEXT_SAME_TITHI"/>	
	<SCREEN id="SCR_ID_INDICAL_TITHI_SEND_AS_SMS_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_NEXT_TITHI_IN_YEAR_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_FESTIVAL_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_FESIVAL_OPTION_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_FESTIVAL_TITHI_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_FESTIVAL_DETAILS_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_NO_OF_YEARS_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_FESTIVAL_YEARS_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_DATE_TO_TITHI_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_TITHI_DAY_SELECTION_MENU"/>	
	<SCREEN id="SCR_ID_INDICAL_ONSCREEN_DISPLAY_OPTION_MENU"/>	
	<SCREEN id="SCR_ID_FESTIVAL_LIST_OPTION"/>	
	<SCREEN id="SCR_ID_FESTIVAL_ENTER_YEAR"/>	
	<SCREEN id="SCR_ID_INDICAL_SEND_TITHI"/>	
	<SCREEN id="SCR_ID_INDICAL_YEARLY_TITHI_OPTIONS"/>	
	<SCREEN id="SCR_ID_INDICAL_GO_TO_CAL"/>
	
        <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
<!---------------------------------------------------------------------------------------------------------------------> 	

</APP>
#endif /* defined(__MMI_INDICAL__) */ 
