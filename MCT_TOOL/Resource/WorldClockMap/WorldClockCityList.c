 const TimeZoneStruct TimeZoneData[]= 
{
	{0,	STR_WC_CITY_NONE,	STR_WC_CITYABBRE_NONE,	0,	0,	0},
	{0,	STR_WC_CITY1,	STR_WC_CITYABBRE1,	,	,	},
	{0,	STR_WC_CITY2,	STR_WC_CITYABBRE2,	,	,	},
	{0,	STR_WC_CITY3,	STR_WC_CITYABBRE3,	,	,	},
	{0,	STR_WC_CITY4,	STR_WC_CITYABBRE4,	,	,	},
	{0,	STR_WC_CITY5,	STR_WC_CITYABBRE5,	,	,	},
	{0,	STR_WC_CITY6,	STR_WC_CITYABBRE6,	,	,	},
	{0,	STR_WC_CITY7,	STR_WC_CITYABBRE7,	,	,	},
	{0,	STR_WC_CITY8,	STR_WC_CITYABBRE8,	,	,	},
	{0,	STR_WC_CITY9,	STR_WC_CITYABBRE9,	,	,	},
	{0,	STR_WC_CITY10,	STR_WC_CITYABBRE10,	,	,	},
	{0,	STR_WC_CITY11,	STR_WC_CITYABBRE11,	,	,	},
	{0,	STR_WC_CITY12,	STR_WC_CITYABBRE12,	,	,	},
	{0,	STR_WC_CITY13,	STR_WC_CITYABBRE13,	,	,	}
};

U8 mmi_wc_get_size(void)
{
	return sizeof(TimeZoneData)/sizeof(TimeZoneStruct);
}
