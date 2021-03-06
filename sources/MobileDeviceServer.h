//
//  MobileDeviceServer.h
//  iGadgetManager
//
//  Created by Vitalii Parovishnyk on 12/17/12.
//
//

#import <Foundation/Foundation.h>

@protocol MobileDeviceServerDelegate <NSObject>

@optional
- (void)newDeviceDetected:(NSString*)connectedDevice;
- (void)deviceRemoved;
- (void)updateAppList;

@end

@class FileSystemItem;

@interface MobileDeviceServer : NSObject
{
	NSMutableDictionary*			m_PlistDict;
	id <MobileDeviceServerDelegate>	_delegate;
	BOOL deviceConnected;
}

#define KEY_PATH	@"path"
#define KEY_SIZE	@"size"
#define KEY_DIR		@"isDir"
#define KEY_CONTENT @"content"

@property (nonatomic, strong) id <MobileDeviceServerDelegate> delegate;

- (void) scanForDevice;
- (BOOL) isConnected;
- (NSString *) deviceName;
- (NSString *) deviceProductType;
- (NSString *) deviceProductVersion;
- (NSString *) deviceCapacity;
- (NSString *) deviceSerialNumber;
- (NSString *) devicePhoneNumber;
- (NSString *) deviceClass;
- (NSString *) deviceColor;
- (NSString *) deviceBaseband;
- (NSString *) deviceBootloader;
- (NSString *) deviceHardwareModel;
- (NSString *) deviceUniqueDeviceID;
- (NSString *) deviceCPUArchitecture;
- (NSString *) deviceHardwarePlatform;
- (NSString *) deviceBluetoothAddress;
- (NSString *) deviceWiFiAddress;
- (NSString *) deviceModelNumber;
- (NSString *) deviceActivation;
- (NSString *) deviceAllInfo;
- (NSString *) deviceAFSTotalBytes;
- (NSString *) deviceAFSFreeBytes;
- (void) deviceAFSUninstallAppID:(NSString*) appID;
- (NSArray*) appsList;
- (BOOL) createScrenshotService;
- (NSImage*) takeScreenshot;
- (BOOL) deviceEnterRecovery;
- (BOOL) deviceReboot;
- (BOOL) deviceShutdown;
- (FileSystemItem*) getFileSystem;
@end
