#include "opencv_modules.h"

#ifdef HAVE_OPENCV_PHOTO

#include "photo.h"
#include "photoBindings.h"
#include "photoConstants.h"

NAN_MODULE_INIT(Photo::Init) {
	PhotoConstants::Init(target);
	Nan::SetMethod(target, "fastNlMeansDenoisingColored", FastNlMeansDenoisingColored);
	Nan::SetMethod(target, "fastNlMeansDenoisingColoredAsync", FastNlMeansDenoisingColoredAsync);
	Nan::SetMethod(target, "inpaint", Inpaint);
	Nan::SetMethod(target, "inpaintAsync", InpaintAsync);
};

NAN_METHOD(Photo::FastNlMeansDenoisingColored) {
	FF::executeSyncBinding(
		std::make_shared<PhotoBindings::FastNlMeansDenoisingColoredWorker>(),
		"Photo::FastNlMeansDenoisingColored",
		info
	);
}

NAN_METHOD(Photo::FastNlMeansDenoisingColoredAsync) {
	FF::executeAsyncBinding(
		std::make_shared<PhotoBindings::FastNlMeansDenoisingColoredWorker>(),
		"Photo::FastNlMeansDenoisingColoredAsync",
		info
	);
}

NAN_METHOD(Photo::Inpaint) {
  FF::executeSyncBinding(
    std::make_shared<PhotoBindings::InpaintWorker>(),
    "Photo::Inpaint",
    info
  );
}

NAN_METHOD(Photo::InpaintAsync) {
  FF::executeAsyncBinding(
    std::make_shared<PhotoBindings::InpaintWorker>(),
    "Photo::InpaintAsync",
    info
  );
}

#endif
