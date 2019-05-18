#include <node.h>
#include "ExternalMemTracking.h"

#include "cvTypes/cvTypes.h"
#include "core/core.h"
#include "modules/io/io.h"

int customCvErrorHandler(int status, const char* func_name, const char* err_msg, const char* file_name, int line, void* userdata) {
    std::string msg = "OpenCV Error: (" + std::string(err_msg) + ")"
      + " in " + std::string(func_name)
      + ", in file " + std::string(file_name)
      + ", line " + std::to_string(line)
      + ", status " + std::to_string(status);

    throw std::runtime_error(msg);
    return 0;
}

void init(v8::Local<v8::Object> target) {
	// can be disabled by defining env variable: OPENCV4NODEJS_DISABLE_EXTERNAL_MEM_TRACKING
	ExternalMemTracking::Init(target);

	// override cv error handler to prevent printing cv errors and throw std::exception
	// instead, which can be catched and forwarded to node process
  cv::redirectError(customCvErrorHandler);


	v8::Local<v8::Object> version = Nan::New<v8::Object>();
	Nan::Set(version, FF_NEW_STRING("major"), Nan::New(CV_MAJOR_VERSION));
	Nan::Set(version, FF_NEW_STRING("minor"), Nan::New(CV_MINOR_VERSION));
	Nan::Set(version, FF_NEW_STRING("subminor"), Nan::New(CV_SUBMINOR_VERSION));
	Nan::Set(target, FF_NEW_STRING("version"), version);

	v8::Local<v8::Object> xmodules = Nan::New<v8::Object>();
	Nan::Set(target, FF_NEW_STRING("xmodules"), xmodules);

	CvTypes::Init(target);
	Core::Init(target);
  Io::Init(target);
};

NODE_MODULE(opencv4nodejs, init)
