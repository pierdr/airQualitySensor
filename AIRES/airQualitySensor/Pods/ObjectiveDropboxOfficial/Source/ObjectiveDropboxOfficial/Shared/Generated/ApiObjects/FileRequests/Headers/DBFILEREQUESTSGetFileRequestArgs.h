///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBFILEREQUESTSGetFileRequestArgs;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `GetFileRequestArgs` struct.
///
/// Arguments for `get`.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBFILEREQUESTSGetFileRequestArgs : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The ID of the file request to retrieve.
@property (nonatomic, readonly, copy) NSString *id_;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param id_ The ID of the file request to retrieve.
///
/// @return An initialized instance.
///
- (instancetype)initWithId_:(NSString *)id_;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `GetFileRequestArgs` struct.
///
@interface DBFILEREQUESTSGetFileRequestArgsSerializer : NSObject

///
/// Serializes `DBFILEREQUESTSGetFileRequestArgs` instances.
///
/// @param instance An instance of the `DBFILEREQUESTSGetFileRequestArgs` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBFILEREQUESTSGetFileRequestArgs` API object.
///
+ (nullable NSDictionary *)serialize:(DBFILEREQUESTSGetFileRequestArgs *)instance;

///
/// Deserializes `DBFILEREQUESTSGetFileRequestArgs` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBFILEREQUESTSGetFileRequestArgs` API object.
///
/// @return An instantiation of the `DBFILEREQUESTSGetFileRequestArgs` object.
///
+ (DBFILEREQUESTSGetFileRequestArgs *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END