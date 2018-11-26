///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMUserCustomQuotaArg;
@class DBTEAMUserSelectorArg;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `UserCustomQuotaArg` struct.
///
/// User and their required custom quota in GB (1 TB = 1024 GB).
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMUserCustomQuotaArg : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// (no description).
@property (nonatomic, readonly) DBTEAMUserSelectorArg *user;

/// (no description).
@property (nonatomic, readonly) NSNumber *quotaGb;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param user (no description).
/// @param quotaGb (no description).
///
/// @return An initialized instance.
///
- (instancetype)initWithUser:(DBTEAMUserSelectorArg *)user quotaGb:(NSNumber *)quotaGb;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `UserCustomQuotaArg` struct.
///
@interface DBTEAMUserCustomQuotaArgSerializer : NSObject

///
/// Serializes `DBTEAMUserCustomQuotaArg` instances.
///
/// @param instance An instance of the `DBTEAMUserCustomQuotaArg` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMUserCustomQuotaArg` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMUserCustomQuotaArg *)instance;

///
/// Deserializes `DBTEAMUserCustomQuotaArg` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMUserCustomQuotaArg` API object.
///
/// @return An instantiation of the `DBTEAMUserCustomQuotaArg` object.
///
+ (DBTEAMUserCustomQuotaArg *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
