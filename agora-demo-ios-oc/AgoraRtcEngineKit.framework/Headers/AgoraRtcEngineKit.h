//
//  AgoraRtcEngineKit.h
//  AgoraRtcEngineKit
//
//  Created by Sting Feng on 2015-8-11.
//  Copyright (c) 2015 Agora. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIView VIEW_CLASS;

#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSView VIEW_CLASS;

#endif


typedef NS_ENUM(NSInteger, AgoraRtcErrorCode) {
    AgoraRtc_Error_NoError = 0,
    AgoraRtc_Error_Failed = 1,
    AgoraRtc_Error_InvalidArgument = 2,
    AgoraRtc_Error_NotReady = 3,
    AgoraRtc_Error_NotSupported = 4,
    AgoraRtc_Error_Refused = 5,
    AgoraRtc_Error_BufferTooSmall = 6,
	AgoraRtc_Error_NotInitialized = 7,
	AgoraRtc_Error_InvalidView = 8,
	AgoraRtc_Error_NoPermission = 9,
    AgoraRtc_Error_TimedOut = 10,
    AgoraRtc_Error_Canceled = 11,
    AgoraRtc_Error_TooOften = 12,
    AgoraRtc_Error_BindSocket = 13,
    AgoraRtc_Error_NetDown = 14,
    AgoraRtc_Error_NoBufs = 15,

    AgoraRtc_Error_InvalidVendorKey = 101,
    AgoraRtc_Error_InvalidChannelName = 102,
    AgoraRtc_Error_NoAvailableChannel = 103,
    AgoraRtc_Error_LookupChannelTimeout = 104,
    AgoraRtc_Error_LookupChannelRejected = 105,
    AgoraRtc_Error_OpenChannelTimeout = 106,
    AgoraRtc_Error_OpenChannelRejected = 107,
    AgoraRtc_Error_RequestDeferred = 108,
    AgoraRtc_Error_DynamicKeyTimeout = 109,
    
    AgoraRtc_Error_LoadMediaEngine = 1001,
    AgoraRtc_Error_StartCall = 1002,
    AgoraRtc_Error_StartCamera = 1003,
	AgoraRtc_Error_StartVideoRender = 1004,
	AgoraRtc_Error_Adm_GeneralError = 1005,
	AgoraRtc_Error_Adm_JavaResource = 1006,
	AgoraRtc_Error_Adm_SampleRate = 1007,
	AgoraRtc_Error_Adm_InitPlayout = 1008,
	AgoraRtc_Error_Adm_StartPlayout = 1009,
	AgoraRtc_Error_Adm_StopPlayout = 1010,
	AgoraRtc_Error_Adm_InitRecording = 1011,
	AgoraRtc_Error_Adm_StartRecording = 1012,
	AgoraRtc_Error_Adm_StopRecording = 1013,
    AgoraRtc_Error_Adm_RuntimePlayoutWarning = 1014,
    AgoraRtc_Error_Adm_RuntimePlayoutError = 1015,
    AgoraRtc_Error_Adm_RuntimeRecordingWarning = 1016,
    AgoraRtc_Error_Adm_RuntimeRecordingError = 1017,
    AgoraRtc_Error_Adm_RecordAudioFailed = 1018,
    AgoraRtc_Error_Adm_RecordAudioSilence = 1019,
    AgoraRtc_Error_Adm_PlaybackAbnormalFrequency = 1020,
    AgoraRtc_Error_Adm_RecordAbnormalFrequency = 1021,
};

typedef NS_ENUM(NSInteger, AgoraRtcVideoProfile) {
                                            // res       fps  kbps
    AgoraRtc_VideoProfile_120P = 0,         // 160x120   15   80
    AgoraRtc_VideoProfile_120P_2 = 1,		// 120x160   15   80
    AgoraRtc_VideoProfile_120P_3 = 2,		// 120x120   15   60
    AgoraRtc_VideoProfile_180P = 10,		// 320x180   15   160
    AgoraRtc_VideoProfile_180P_2 = 11,		// 180x320   15   160
    AgoraRtc_VideoProfile_180P_3 = 12,		// 180x180   15   120
    AgoraRtc_VideoProfile_240P = 20,		// 320x240   15   200
    AgoraRtc_VideoProfile_240P_2 = 21,		// 240x320   15   200
    AgoraRtc_VideoProfile_240P_3 = 22,		// 240x240   15   160
    AgoraRtc_VideoProfile_360P = 30,		// 640x360   15   400
    AgoraRtc_VideoProfile_360P_2 = 31,		// 360x640   15   400
    AgoraRtc_VideoProfile_360P_3 = 32,		// 360x360   15   300
    AgoraRtc_VideoProfile_360P_4 = 33,		// 640x360   30   680
    AgoraRtc_VideoProfile_360P_5 = 34,		// 360x640   30   680
    AgoraRtc_VideoProfile_360P_6 = 35,		// 360x360   30   500
    AgoraRtc_VideoProfile_480P = 40,		// 640x480   15   500
    AgoraRtc_VideoProfile_480P_2 = 41,		// 480x640   15   500
    AgoraRtc_VideoProfile_480P_3 = 42,		// 480x480   15   400
    AgoraRtc_VideoProfile_480P_4 = 43,		// 640x480   30   750
    AgoraRtc_VideoProfile_480P_5 = 44,		// 480x640   30   750
    AgoraRtc_VideoProfile_480P_6 = 45,		// 480x480   30   680
    AgoraRtc_VideoProfile_720P = 50,		// 1280x720  15   1000
    AgoraRtc_VideoProfile_720P_2 = 51,		// 720x1280  15   1000
    AgoraRtc_VideoProfile_720P_3 = 52,		// 1280x720  30   1700
    AgoraRtc_VideoProfile_720P_4 = 53,		// 720x1280  30   1700
    AgoraRtc_VideoProfile_1080P = 60,		// 1920x1080 15   1500
    AgoraRtc_VideoProfile_1080P_2 = 61,		// 1080x1920 15   1500
    AgoraRtc_VideoProfile_1080P_3 = 62,		// 1920x1920 30   2550
    AgoraRtc_VideoProfile_1080P_4 = 63,		// 1080x1920 30   2550
    AgoraRtc_VideoProfile_1080P_5 = 64,		// 1920x1080 60   4300
    AgoraRtc_VideoProfile_1080P_6 = 65,		// 1080x1920 60   4300
    AgoraRtc_VideoProfile_4K = 70,			// 3840x2160 30   8000
    AgoraRtc_VideoProfile_4K_2 = 71,		// 2160x3080 30   8000
    AgoraRtc_VideoProfile_4K_3 = 72,		// 3840x2160 60   13600
    AgoraRtc_VideoProfile_4K_4 = 73,		// 2160x3840 60   13600
    AgoraRtc_VideoProfile_DEFAULT = AgoraRtc_VideoProfile_360P,
};

typedef NS_ENUM(NSUInteger, AgoraRtcQuality) {
    AgoraRtc_Quality_Unknown = 0,
    AgoraRtc_Quality_Excellent = 1,
    AgoraRtc_Quality_Good = 2,
    AgoraRtc_Quality_Poor = 3,
    AgoraRtc_Quality_Bad = 4,
    AgoraRtc_Quality_VBad = 5,
    AgoraRtc_Quality_Down = 6,
};

typedef NS_ENUM(NSUInteger, AgoraRtcLogFilter) {
    AgoraRtc_LogFilter_Debug = 0x0800,
    AgoraRtc_LogFilter_Info = 0x0001,
    AgoraRtc_LogFilter_Warn = 0x0002,
    AgoraRtc_LogFilter_Error = 0x0004,
    AgoraRtc_LogFilter_Critical = 0x0008,
};


typedef NS_ENUM(NSUInteger, AgoraRtcRenderMode) {
    /**
     Hidden(1): If the video size is different than that of the display window, crops the borders of the video (if the video is bigger) or stretch the video (if the video is smaller) to fit it in the window.
     */
    AgoraRtc_Render_Hidden = 1,
    
    /**
     AgoraRtc_Render_Fit(2): If the video size is different than that of the display window, resizes the video proportionally to fit the window.
     */
    AgoraRtc_Render_Fit = 2,
    
    /**
     AgoraRtc_Render_Adaptive(3)：If both callers use the same screen orientation, i.e., both use vertical screens or both use horizontal screens, the AgoraRtc_Render_Hidden mode applies; if they use different screen orientations, i.e., one vertical and one horizontal, the AgoraRtc_Render_Fit mode applies.
     */
    AgoraRtc_Render_Adaptive = 3,
};

typedef NS_ENUM(NSUInteger, AgoraRtcQualityReportFormat) {
    AgoraRtc_QualityReportFormat_Json = 0,
    AgoraRtc_QualityReportFormat_Html = 1,
};

__attribute__((visibility("default"))) @interface AgoraRtcVideoCanvas : NSObject

/**
 *  The video display view. The SDK does not maintain the lifecycle of the view.
    The view can be safely released after calling leaveChannel with a returned value. 
    The SDK keeps a cache of the view value, so 'setupLocalVideo' to set the view value to NULL could be able to clear cache before switching or releasing view.
 */
@property (strong, nonatomic) VIEW_CLASS* view;
@property (assign, nonatomic) AgoraRtcRenderMode renderMode; // the render mode of view: hidden, fit and adaptive
@property (assign, nonatomic) NSUInteger uid; // the user id of view
@end


__attribute__((visibility("default"))) @interface AgoraRtcStats : NSObject
@property (assign, nonatomic) NSUInteger duration;
@property (assign, nonatomic) NSUInteger txBytes;
@property (assign, nonatomic) NSUInteger rxBytes;
@end

__attribute__((visibility("default"))) @interface AgoraRtcAudioVolumeInfo : NSObject
@property (assign, nonatomic) NSUInteger uid;
@property (assign, nonatomic) NSUInteger volume;
@end

@class AgoraRtcEngineKit;
@protocol AgoraRtcEngineDelegate <NSObject>
@optional
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didOccurWarning:(AgoraRtcErrorCode)warningCode;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didOccurError:(AgoraRtcErrorCode)errorCode;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine reportAudioVolumeIndicationOfSpeakers:(NSArray*)speakers totalVolume:(NSInteger)totalVolume;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine firstLocalVideoFrameWithSize:(CGSize)size elapsed:(NSInteger)elapsed;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine firstRemoteVideoDecodedOfUid:(NSUInteger)uid size:(CGSize)size elapsed:(NSInteger)elapsed;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine firstRemoteVideoFrameOfUid:(NSUInteger)uid size:(CGSize)size elapsed:(NSInteger)elapsed;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didJoinedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didOfflineOfUid:(NSUInteger)uid;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine localVideoStatWithSentBitrate:(NSInteger)sentBitrate sentFrameRate:(NSInteger)sentFrameRate;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine remoteVideoStatOfUid:(NSUInteger)uid delay:(NSInteger)delay receivedBitrate:(NSInteger)receivedBitrate receivedFrameRate:(NSInteger)receivedFrameRate;
- (void)rtcEngineCameraDidReady:(AgoraRtcEngineKit *)engine;
- (void)rtcEngineVideoDidStop:(AgoraRtcEngineKit *)engine;
- (void)rtcEngineConnectionDidLost:(AgoraRtcEngineKit *)engine;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didJoinChannel:(NSString*)channel withUid:(NSUInteger)uid elapsed:(NSInteger) elapsed;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didRejoinChannel:(NSString*)channel withUid:(NSUInteger)uid elapsed:(NSInteger) elapsed;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine reportRtcStats:(AgoraRtcStats*)stats;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine didLeaveChannelWithStats:(AgoraRtcStats*)stats;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine audioQualityOfUid:(NSUInteger)uid quality:(AgoraRtcQuality)quality delay:(NSUInteger)delay lost:(NSUInteger)lost;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine networkQuality:(AgoraRtcQuality)quality;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine mediaEngineEvent:(NSInteger)event;
- (void)rtcEngine:(AgoraRtcEngineKit *)engine receiveVendorMessageFromUid:(NSUInteger)uid data:(NSData*)data;
@end


__attribute__((visibility("default"))) @interface AgoraRtcEngineKit : NSObject

/**
*  Get the version of Agora SDK.
*
*  @return string, sdk version
*/
+ (NSString *)getSdkVersion;

/**
 *  Get the version of Media Engine
 *
 *  @return string, engine version
 */
+ (NSString *)getMediaEngineVersion;
- (void*)getEngine;


/**
 *  Initializes the AgoraRtcEngineKit object.
 *
 *  @param key      The vendor key is issued to the application developers by Agora.
 *  @param delegate
 *
 *  @return an object of AgoraRtcEngineKit class
 */
- (id)initWithVendorKey:(NSString*)key
               delegate:(id<AgoraRtcEngineDelegate>)delegate;

/**
 *  deprecated
 */
- (id)initWithVendorKey:(NSString*)key
                  error:(void(^)(AgoraRtcErrorCode errorCode))errorBlock __deprecated;

/**
 * deprecated blocks
 */
- (void)audioVolumeIndicationBlock:(void(^)(NSArray *speakers, NSInteger totalVolume))audioVolumeIndicationBlock __deprecated;

- (void)firstLocalVideoFrameBlock:(void(^)(NSInteger width, NSInteger height, NSInteger elapsed))firstLocalVideoFrameBlock __deprecated;
- (void)firstRemoteVideoDecodedBlock:(void(^)(NSUInteger uid, NSInteger width, NSInteger height, NSInteger elapsed))firstRemoteVideoDecodedBlock __deprecated;
- (void)firstRemoteVideoFrameBlock:(void(^)(NSUInteger uid, NSInteger width, NSInteger height, NSInteger elapsed))firstRemoteVideoFrameBlock __deprecated;
- (void)userJoinedBlock:(void(^)(NSUInteger uid, NSInteger elapsed))userJoinedBlock __deprecated;
- (void)userOfflineBlock:(void(^)(NSUInteger uid))userOfflineBlock __deprecated;
- (void)userMuteAudioBlock:(void(^)(NSUInteger uid, BOOL muted))userMuteAudioBlock __deprecated;
- (void)userMuteVideoBlock:(void(^)(NSUInteger uid, BOOL muted))userMuteVideoBlock __deprecated;
- (void)localVideoStatBlock:(void(^)(NSInteger sentBitrate, NSInteger sentFrameRate))localVideoStatBlock __deprecated;
- (void)remoteVideoStatBlock:(void(^)(NSUInteger uid, NSInteger delay, NSInteger receivedBitrate, NSInteger receivedFrameRate))remoteVideoStatBlock __deprecated;
- (void)cameraReadyBlock:(void(^)())cameraReadyBlock __deprecated;
- (void)connectionLostBlock:(void(^)())connectionLostBlock __deprecated;
- (void)rejoinChannelSuccessBlock:(void(^)(NSString* channel, NSUInteger uid, NSInteger elapsed))rejoinChannelSuccessBlock __deprecated;
- (void)rtcStatsBlock:(void(^)(AgoraRtcStats* stat))rtcStatsBlock __deprecated;
- (void)leaveChannelBlock:(void(^)(AgoraRtcStats* stat))leaveChannelBlock __deprecated;
- (void)audioQualityBlock:(void(^)(NSUInteger uid, AgoraRtcQuality quality, NSUInteger delay, NSUInteger lost))audioQualityBlock __deprecated;
- (void)networkQualityBlock:(void(^)(AgoraRtcQuality quality))networkQualityBlock __deprecated;
- (void)mediaEngineEventBlock:(void(^)(NSInteger code))mediaEngineEventBlock __deprecated;
- (void)vendorMessageBlock:(void(^)(NSUInteger uid, NSData* data))vendorMessageBlock __deprecated;


/** BEGIN OF COMMON METHODS */

/**
 *  Create an open UDP socket to the AgoraRtcEngineKit cloud service to join a channel.
    Users in the same channel can talk to each other with same vendor key.
    Users using different vendor keys cannot call each other.
    The method is asynchronous.
 *
 *  @param key               Account level credentials issued by AgoraLab company to each vendor.
 *  @param channelName       Joining in the same channel indicates those clients have entered in one room.
 *  @param info              Optional, this argument can be whatever the programmer likes personally.
 *  @param uid               Optional, this argument is the unique ID for each member in one channel.
                             If not specified, or set to 0, the SDK automatically allocates an ID, and the id could be gotten in onJoinChannelSuccess.
 *  @param joinSuccdessBlock
 *
 *  @return 0 when executed successfully, and return minus value when failed.
 */
- (int)joinChannelByKey:(NSString *)key
             channelName:(NSString *)channelName
                    info:(NSString *)info
                     uid:(NSUInteger)uid
                 joinSuccess:(void(^)(NSString* channel, NSUInteger uid, NSInteger elapsed))joinSuccessBlock;

/**
 *  lets the user leave a channel, i.e., hanging up or exiting a call.
    After joining a channel, the user must call the leaveChannel method to end the call before joining another one.
    It is synchronous, i.e., it only returns until the call ends and all resources are released.
 *  @param leaveChannelBlock indicate the statistics of this call, from joinChannel to leaveChannel, including duration, tx bytes and rx bytes in the call.
 *
 *  @return 0 if executed successfully, or return minus value if failed.
 */
- (int)leaveChannel:(void(^)(AgoraRtcStats* stat))leaveChannelBlock;

/**
 *  Disables the network quality test.
 *
 *  @return 0 when executed successfully, and return minus value when failed.
 */
- (int)enableNetworkTest;

/**
 *  Enables the network quality test. When enabled, the callback 'networkQualityBlock' notifies the application about the user's network connection quality.
 Note: Once the network test is enabled, it uses the network bandwidth even when the application is not in a call.
 Recommandation: When the application is foreground, enable the network connection test; and when the application is switched to background, disable network test  in order to reduce network traffic.
 By default, the network test is disabled
 *
 *  @return 0 when executed successfully, and return minus value when failed.
 */
- (int)disableNetworkTest;

/**
 *  Enables video mode.  Switches from audio to video mode.
    It could be called during a call and before entering a channel.
 *
 *  @return 0 when this method is called successfully, or minus value when this method failed.
 */
- (int)enableVideo;

/**
 *  Disable video mode. Switch from video to audio mode.
    It could be called during a call and before entering a channel.
 *
 *  @return 0 when this method is called successfully, or minus value when this method failed.
 */
- (int)disableVideo;

/**
 *  start local video preview, while not sending data to server
 *
 *  @return 0 when this method is called successfully, or minus value when this method failed.
 */
- (int)startPreview;

/**
 *  stop local video preview
 *
 *  @return 0 when this method is called successfully, or minus value when this method failed.
 */
- (int)stopPreview;

- (int)enableVendorMessage;
- (int)disableVendorMessage;
- (int)sendVendorMessage:(NSData*)data;

/**
 *  Specify sdk parameters
 *
 *  @param options, sdk options in json format.
 */
- (int)setParameters:(NSString *)options;

/**
 *  Generates a URL linking to the call quality reports.
 *
 *  @param channel      The channel name specified in the joinChannel method.
 *  @param listenerUid  The uid of the listener.
 *  @param speakerUid   The uid of the speaker.
 *  @param reportFormat The format of the report.
                        AgoraRtc_QualityReportFormat_Json (0): JSON.: Returns the quality report data in Json.
                        AgoraRtc_QualityReportFormat_Html (1): HTML.: Returns a report in HTML format, displayed on a web browser or WebVIEW components.
 *
 *  @return 0 when executed successfully. return minus value when failed. return AgoraRtc_Error_Invalid_Argument (-2)：Invalid argument. return AgoraRtc_Error_Buffer_Too_Small (-6)：The buffer length is too small.
 */
- (NSString*) makeQualityReportUrl:(NSString*) channel
                       listenerUid:(NSUInteger) listenerUid
                       speakerrUid:(NSUInteger) speakerUid
                      reportFormat:(AgoraRtcQualityReportFormat) reportFormat;

/**
 *  The call id of current client. The call id could be used in 'rate' and 'complain' method.
 *
 *  @return The current call id.
 */
- (NSString*) getCallId;

/**
 *  Let user rate the call. Often called after the call ends.
 *
 *  @param callId      The call ID retrieved from the 'getCallId' method.
 *  @param rating      The rating for the call between 1 (lowest score) to 10 (highest score).
 *  @param description Optional, decribed by user for the call with a length less than 800 bytes.
 *
 *  @return 0 when executed successfully. return ERR_INVALID_ARGUMENT (-2)：The passed argument is invalid, e.g., callId invalid. return ERR_NOT_READY (-3)：The SDK status is incorrect, e.g., initialization failed.
 */
- (int) rate:(NSString*) callId
      rating:(NSInteger) rating
 description:(NSString*) description;

/**
 *  Let user complain the quality of the call. Often called after the call ends.
 *
 *  @param callId      The call ID retrieved from the 'getCallId' method.
 *  @param description Optional, decribed by user for the call with a length less than 800 bytes.
 *
 *  @return 0 when executed successfully. return ERR_INVALID_ARGUMENT (-2)：The passed argument is invalid, e.g., callId invalid. return ERR_NOT_READY (-3)：The SDK status is incorrect, e.g., initialization failed.
 */
- (int) complain:(NSString*) callId
     description:(NSString*) description;

/** END OF COMMON METHODS */

/** BEGIN OF AUDIO METHODS */


/**
 *  Enable / Disable speaker of device
 *
 *  @param mute true: Switches to speakerphone. false: Switches to headset.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setEnableSpeakerphone:(BOOL)enableSpeaker;

/**
 *  test if the speakerphone is enabled or not.
 *
 *  @return true when speakerphone is enabled. false when speakerphone is not enabled.
 */
- (BOOL)isSpeakerphoneEnabled;


/**
 *  Sets the speakerphone volume.
 *
 *  @param volume between 0 (lowest volume) to 255 (highest volume).
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setSpeakerphoneVolume:(NSUInteger)volume;


/**
 *  Enables to report to the application about the volume of the speakers.
 *
 *  @param interval Specifies the time interval between two consecutive volume indications.
                    <=0: Disables volume indication.
                    >0 : The volume indication interval in milliseconds. Recommandation: >=200ms.
 *  @param smooth   The smoothing factor. Recommended: 3.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)enableAudioVolumeIndication:(NSInteger)interval
               smooth:(NSInteger)smooth;


/**
 *  Start recording conversation to file specified by the file path.
 *
 *  @param filePath file path to save recorded conversation.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)startAudioRecording:(NSString*)filePath;


/**
 *  Stop conversation recording
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)stopAudioRecording;


/**
 *  Launches an echo test to test if the audio devices (e.g., headset and speaker) and the network connection work properly. In the test, the user speaks first, and the recording will be played back in 10 seconds. If the user can hear what he said in 10 seconds, it indicates that the audio devices and network connection work properly.
 Notes: Must call stopEchoTest to end the test, or won't start new test or join channel.
 *
 *  @param successBlock
 *
 *  @return 0 when executed successfully. return minus value if failed. e.g. ERR_REFUSED (-5)：Failed to launch the echo test, e.g., initialization failed.
 */
- (int)startEchoTest:(void(^)(NSString* channel, NSUInteger uid, NSInteger elapsed))successBlock;

/**
 *  Stop echo test.
 *
 *  @return 0 when executed successfully. return minus value if failed. e.g. ERR_REFUSED(-5)：Failed to stop the echo test. It could be that the echo test is not running.
 */
- (int)stopEchoTest;

/**
 *  Mutes / Unmutes local audio.
 *
 *  @param mute true: Mutes the local audio. false: Unmutes the local audio.
 *
 *  @return 0 when executed successfully. return minus value if failed. 
 */
- (int)muteLocalAudioStream:(BOOL)mute;


/**
 *  Mutes / Unmutes all remote audio.
 *
 *  @param mute true: Mutes all remote received audio. false: Unmutes all remote received audio.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */

- (int)muteAllRemoteAudioStreams:(BOOL)mute;

/** END OF AUDIO METHODS */

/** BEGIN OF VIDIO METHODS */

/**
 *  Set up the local video view. The video canvus is initialized with video display setting. And it could be called before entering a channel.
 *
 *  @param local the canvas is composed of view, renderMode and uid. How to initialize 'local'? please take a look at 'AgoraRtcVideoCanvas'
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setupLocalVideo:(AgoraRtcVideoCanvas*)local;


/**
 *  Set up the remote video view. The video canvus is initialized with video display setting. It could be called after receiving the remote video streams to configure the video settings.
 *
 *  @param remote the canvas is composed of view, renderMode and uid. How to initialize 'remote'? please take a look at 'AgoraRtcVideoCanvas'
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setupRemoteVideo:(AgoraRtcVideoCanvas*)remote;


/**
 *  Configure display setting of local view. And it could be called mutiple times during a call.
 *
 *  @param mode There are Hidden(1), Fit(2) and Adaptive(3) mode. Please take a look at definition of enum AgoraRtcRenderMode
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setLocalRenderMode:(AgoraRtcRenderMode) mode;


/**
 *  Configure display setting of remote view. And it could be called mutiple times during a call.
 *
 *  @param uid  The user id of remote view.
 *  @param mode There are Hidden(1), Fit(2) and Adaptive(3) mode. Please take a look at definition of enum AgoraRtcRenderMode
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setRemoteRenderMode: (NSUInteger)uid
                      mode:(AgoraRtcRenderMode) mode;

/**
 *   Switches between video display views of two different users.
 *
 *  @param uid1 The user ID of the user whose video is to be switched.
 *  @param uid2 The user ID of another user whose video is to be switched.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)switchView:(NSUInteger)uid1
       andAnother:(NSUInteger)uid2;


/**
 *  Switches between front and back cameras.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)switchCamera;

/**
 *  set video profile, including resolution, fps, kbps
 *
 *  @param profile enumeration definition about the video resolution, fps and max kbps
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setVideoProfile:(AgoraRtcVideoProfile)profile;


/**
 *  Enable / disable sending local video streams to the network.
 *
 *  @param mute true: stop sending local video stream to the network, false: start sending local video stream.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)muteLocalVideoStream:(BOOL)mute;


/**
 *  Enables / disables playing all remote callers’ video streams.
 *
 *  @param mute true: stop playing, false: start playing.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)muteAllRemoteVideoStreams:(BOOL)mute;

/** END OF VIDIO METHODS */

/**
 *  Specifies the SDK output log file.
 *
 *  @param filePath The full file path of the log file.
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)setLogFile:(NSString*)filePath;

/**
 *  Renew dynamic key, refresh the new key into agora engine. APP should call this API when SDK reports error ERR_DYNAMIC_KEY_TIMEOUT.
 *
 *  @param key the new dynamic key
 *
 *  @return 0 when executed successfully. return minus value if failed.
 */
- (int)renewDynamicKey:(NSString*)key;

@end
