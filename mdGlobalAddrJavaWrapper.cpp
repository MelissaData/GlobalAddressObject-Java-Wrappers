#include <jni.h>

#include "mdGlobalAddr.h"

class Utf8String {
	private:
		JNIEnv* env;
		const char* utf8Ptr;
		jstring jString;
	public:
		Utf8String(JNIEnv* jEnv,jstring str);
		~Utf8String();
		const char* GetUtf8Ptr();
};

Utf8String::Utf8String(JNIEnv* jEnv,jstring str) {
	env=jEnv;
	jString=str;
	if (jString!=0)
		utf8Ptr=env->GetStringUTFChars(jString,0);
	else
		utf8Ptr=0;
}

Utf8String::~Utf8String() {
	if (utf8Ptr!=0)
		env->ReleaseStringUTFChars(jString,utf8Ptr);
}

const char* Utf8String::GetUtf8Ptr() {
	if (utf8Ptr!=0)
		return utf8Ptr;
	return "";
}

jstring UnicodeString(JNIEnv* jEnv,const char* str) {
	if (str!=0)
		return jEnv->NewStringUTF(str);
	return jEnv->NewStringUTF("");
}

extern "C" JNIEXPORT jlong JNICALL Java_com_melissadata_mdGlobalAddrJNI_mdGlobalAddrCreate(JNIEnv* /*jEnv*/,jclass /*jCls*/) {
	return (jlong) new mdGlobalAddr();
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGlobalAddrJNI_mdGlobalAddrDestroy(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	delete (mdGlobalAddr*) I;
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdGlobalAddrJNI_SetLicenseString(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	return (jboolean) ((mdGlobalAddr*) I)->SetLicenseString(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGlobalAddrJNI_SetPathToGlobalAddrFiles(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring p1) {
	Utf8String _p1(jEnv,p1);
	((mdGlobalAddr*) I)->SetPathToGlobalAddrFiles(_p1.GetUtf8Ptr());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdGlobalAddrJNI_InitializeDataFiles(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jint) ((mdGlobalAddr*) I)->InitializeDataFiles();
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGlobalAddrJNI_ClearProperties(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	((mdGlobalAddr*) I)->ClearProperties();
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdGlobalAddrJNI_SetInputParameter(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszParamName,jstring pszParamValue) {
	Utf8String _pszParamName(jEnv,pszParamName);
	Utf8String _pszParamValue(jEnv,pszParamValue);
	return (jboolean) ((mdGlobalAddr*) I)->SetInputParameter(_pszParamName.GetUtf8Ptr(),_pszParamValue.GetUtf8Ptr());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdGlobalAddrJNI_VerifyAddress(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jint) ((mdGlobalAddr*) I)->VerifyAddress();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_GetOutputParameter(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszParamName) {
	Utf8String _pszParamName(jEnv,pszParamName);
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->GetOutputParameter(_pszParamName.GetUtf8Ptr()));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_TransliterateText(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszInput,jstring pszInputScript,jstring pszOutputScript) {
	Utf8String _pszInput(jEnv,pszInput);
	Utf8String _pszInputScript(jEnv,pszInputScript);
	Utf8String _pszOutputScript(jEnv,pszOutputScript);
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->TransliterateText(_pszInput.GetUtf8Ptr(),_pszInputScript.GetUtf8Ptr(),_pszOutputScript.GetUtf8Ptr()));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_GetCurrentAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->GetCurrentAtomSet());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_InputsAsAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->InputsAsAtomSet());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_RightFieldResultsAsAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszAtomSet) {
	Utf8String _pszAtomSet(jEnv,pszAtomSet);
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->RightFieldResultsAsAtomSet(_pszAtomSet.GetUtf8Ptr()));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_TokenizerResultsAsAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszAtomSet) {
	Utf8String _pszAtomSet(jEnv,pszAtomSet);
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->TokenizerResultsAsAtomSet(_pszAtomSet.GetUtf8Ptr()));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_InputMapperResultsAsAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszAtomSetArray) {
	Utf8String _pszAtomSetArray(jEnv,pszAtomSetArray);
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->InputMapperResultsAsAtomSet(_pszAtomSetArray.GetUtf8Ptr()));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_MatchEngineResultsAsAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszAtomSetArray) {
	Utf8String _pszAtomSetArray(jEnv,pszAtomSetArray);
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->MatchEngineResultsAsAtomSet(_pszAtomSetArray.GetUtf8Ptr()));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdGlobalAddrJNI_OutputMappingResultsAsAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszAtomSet) {
	Utf8String _pszAtomSet(jEnv,pszAtomSet);
	return UnicodeString(jEnv,((mdGlobalAddr*) I)->OutputMappingResultsAsAtomSet(_pszAtomSet.GetUtf8Ptr()));
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdGlobalAddrJNI_SetOutputsFromAtomSet(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring pszAtomSet) {
	Utf8String _pszAtomSet(jEnv,pszAtomSet);
	((mdGlobalAddr*) I)->SetOutputsFromAtomSet(_pszAtomSet.GetUtf8Ptr());
}

