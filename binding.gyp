{
	"targets": [{
		"target_name": "opencv4nodejs",
		"defines": [
			"<!@(node ./lib/defines.js)",
		],
		"include_dirs" : [
			"<!@(node ./lib/includes.js)",
			"cc",
			"cc/core",
			"cc/modules",
			"<!(node -e \"require('nan')\")",
			"<!(node -e \"require('macro-inferno')\")",
			"<!(node -e \"require('native-node-utils')\")"
		],
		"libraries": [
			"<!@(node ./lib/libs.js)"
		],
		"sources": [
			"cc/opencv4nodejs.cc",
			"cc/CustomMatAllocator.cc",
			"cc/ExternalMemTracking.cc",
			"cc/cvTypes/cvTypes.cc",
			"cc/cvTypes/imgprocConstants.cc",
			"cc/cvTypes/photoConstants.cc",
			"cc/cvTypes/videoCaptureProps.cc",
			"cc/core/core.cc",
			"cc/core/Mat.cc",
			"cc/core/MatImgproc.cc",
			"cc/core/Point.cc",
			"cc/core/Vec.cc",
			"cc/core/Size.cc",
			"cc/core/Rect.cc",
			"cc/core/RotatedRect.cc",
			"cc/core/TermCriteria.cc",
			"cc/modules/io/io.cc",
		],
		"cflags" : [
			"-std=c++11"
		],
		"cflags!" : [
			"-fno-exceptions"
		],
		"cflags_cc!": [
			"-fno-rtti",
			"-fno-exceptions"
		],
		"ldflags" : [
			"-Wl,-rpath,'$$ORIGIN'"
		],
		"xcode_settings": {
			"OTHER_CFLAGS": [
				"-std=c++11",
				"-stdlib=libc++"
			],
			"GCC_ENABLE_CPP_EXCEPTIONS": "YES",
			"MACOSX_DEPLOYMENT_TARGET": "10.9"
		},
		"conditions": [
			[ "OS==\"win\"", {
				"cflags": [
					"-Wall"
				],
				"defines": [
					"WIN",
					"_HAS_EXCEPTIONS=1"
				],
				"msvs_settings": {
					"VCCLCompilerTool": {
						"ExceptionHandling": "2",
						"RuntimeLibrary": "2"
					},
				}
			}],
		],

		"configurations": {
			"Debug": {
				"cflags": ["--coverage"],
				"ldflags": ["--coverage"]
			},
		}
	}]
}
