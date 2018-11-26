///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBFILESCreateFolderBatchArg;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `CreateFolderBatchArg` struct.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBFILESCreateFolderBatchArg : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// List of paths to be created in the user's Dropbox. Duplicate path arguments
/// in the batch are considered only once.
@property (nonatomic, readonly) NSArray<NSString *> *paths;

/// If there's a conflict, have the Dropbox server try to autorename the folder
/// to avoid the conflict.
@property (nonatomic, readonly) NSNumber *autorename;

/// Whether to force the create to happen asynchronously.
@property (nonatomic, readonly) NSNumber *forceAsync;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param paths List of paths to be created in the user's Dropbox. Duplicate
/// path arguments in the batch are considered only once.
/// @param autorename If there's a conflict, have the Dropbox server try to
/// autorename the folder to avoid the conflict.
/// @param forceAsync Whether to force the create to happen asynchronously.
///
/// @return An initialized instance.
///
- (instancetype)initWithPaths:(NSArray<NSString *> *)paths
                   autorename:(nullable NSNumber *)autorename
                   forceAsync:(nullable NSNumber *)forceAsync;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param paths List of paths to be created in the user's Dropbox. Duplicate
/// path arguments in the batch are considered only once.
///
/// @return An initialized instance.
///
- (instancetype)initWithPaths:(NSArray<NSString *> *)paths;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `CreateFolderBatchArg` struct.
///
@interface DBFILESCreateFolderBatchArgSerializer : NSObject

///
/// Serializes `DBFILESCreateFolderBatchArg` instances.
///
/// @param instance An instance of the `DBFILESCreateFolderBatchArg` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBFILESCreateFolderBatchArg` API object.
///
+ (nullable NSDictionary *)serialize:(DBFILESCreateFolderBatchArg *)instance;

///
/// Deserializes `DBFILESCreateFolderBatchArg` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBFILESCreateFolderBatchArg` API object.
///
/// @return An instantiation of the `DBFILESCreateFolderBatchArg` object.
///
+ (DBFILESCreateFolderBatchArg *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
