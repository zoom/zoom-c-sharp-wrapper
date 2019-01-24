#pragma once
#define BEGIN_CLASS_DEFINE_WITHCALLBACK(Classname, CallBackClass)\
class CSDKWrap;\
class CSDKExtWrap;\
class Classname##Wrap : public Classname, public CallBackClass \
{\
CallBackClass* external_cb;
#define STAITC_CLASS(Classname) \
friend CSDKWrap;\
friend CSDKExtWrap;\
private:\
	Classname##Wrap(){m_obj = NULL;external_cb=NULL;};\
	static Classname##Wrap& GetInst(){static Classname##Wrap inst; return inst;};\
public:
