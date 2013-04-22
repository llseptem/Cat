#include "CatDeviceManager.h"
#include <visa.h>

CatDeviceManager::CatDeviceManager(QObject *parent)
	: QObject(parent)
{
	::CoInitialize(NULL);
	ptr34980 = IAgilent34980A2Ptr(__uuidof(Agilent34980A));
	ptr34411 = IAgilent34410Ptr(__uuidof(Agilent34410));
}

CatDeviceManager::~CatDeviceManager()
{
// 	if(ptr34980)
// 		ptr34980->Close();
// 	if(ptr34411)
// 		ptr34411->Close();
	::CoUninitialize();
}

CatDeviceManager& CatDeviceManager::GetInstance()
{
	static CatDeviceManager mgr;
	return mgr;
}

IAgilent34980A2Ptr CatDeviceManager::Get34980() const
{
	return ptr34980;
}

IAgilent34410Ptr CatDeviceManager::Get34411() const
{
	return ptr34411;
}
static const char* strStandardInitOptions = "Cache=true, InterchangeCheck=false, QueryInstrStatus=true, RangeCheck=true, RecordCoercions=false, Simulate=false";
bool CatDeviceManager::Initialize()
{
	try
	{
		ViSession session,defrm;
		ViStatus VISAstatus;
		int overcurron;
		float voltsetting,currsetting,overvoltsetting;

		char add[]="USB0::0x0957::0x0807::N5765A-US12N5190H::0::INSTR";

		voltsetting=12; //in volts                   //输出电压

		currsetting=30; //in amps                 //输出电流

		overvoltsetting=13.5;  //in volts           //输出电压保护

		overcurron=1;                            //输出电流保护状态：打开

		//The default resource manager manages initializes the VISA system
		VISAstatus=viOpenDefaultRM(&defrm);
		if (VISAstatus!=VI_SUCCESS) 
		{
			return false;
		}
		//opens a communication session with the instrument at address "add"
		VISAstatus=viOpen(defrm,add,VI_NULL,VI_NULL,&session);
		if (VISAstatus!=VI_SUCCESS) 
		{
			return false;
		}

		//Set voltage
		viPrintf(session,"VOLT %f \n",voltsetting);

		//Set the over voltage level
		viPrintf(session,"VOLT:PROT:LEV %f \n",overvoltsetting);

		//Turn on over current protection 
		viPrintf(session,"CURR:PROT:STAT %d \n",overcurron);

		//Set current level
		viPrintf(session,"CURR %f \n",currsetting);

		//Enable the output
		viPrintf(session,"OUTP ON \n");

		//This frees up all of the resources
		viClose(session);
		viClose(defrm);

		IAgilent34980A2Ptr ptr34980 = Get34980();
		ptr34980->Initialize("USB0::0x0957::0x0507::MY52490246::0::INSTR", VARIANT_FALSE, VARIANT_TRUE, strStandardInitOptions);
		ptr34980->Status->Clear();

		IAgilent34410Ptr ptr34411 = Get34411();
		ptr34411->Initialize("USB0::0x0957::0x0A07::MY53000110::0::INSTR", VARIANT_FALSE, VARIANT_TRUE, strStandardInitOptions);
		ptr34411->Status->Clear();
		return true;
	}
	catch(_com_error& e)
	{
		return false;
	}
}

void CatDeviceManager::Uinitialize()
{
	try
	{
		ViSession session,defrm;
		int overcurron;
		float voltsetting,currsetting,overvoltsetting;

		char add[]="USB0::0x0957::0x0807::N5765A-US12N5190H::0::INSTR";
		//The default resource manager manages initializes the VISA system
		viOpenDefaultRM(&defrm);

		//opens a communication session with the instrument at address "add"
		viOpen(defrm,add,VI_NULL,VI_NULL,&session);

		//Enable the output
		viPrintf(session,"OUTP OFF \n");

		//This frees up all of the resources
		viClose(session);
		viClose(defrm);

		Get34980()->Close();
		Get34411()->Close();
	}
	catch(_com_error& e)
	{}
}
