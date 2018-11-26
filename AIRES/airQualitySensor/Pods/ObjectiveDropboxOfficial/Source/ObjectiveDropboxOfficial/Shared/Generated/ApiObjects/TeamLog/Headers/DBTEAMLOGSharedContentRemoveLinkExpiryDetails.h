///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGSharedContentRemoveLinkExpiryDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SharedContentRemoveLinkExpiryDetails` struct.
///
/// Removed link expiration date of shared file/folder.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGSharedContentRemoveLinkExpiryDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// Previous shared content link expiration date. Might be missing due to
/// historical data gap.
@property (nonatomic, readonly, nullable) NSDate *previousValue;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param previousValue Previous shared content link expiration date. Might be
/// missing due to historical data gap.
///
/// @return An initialized instance.
///
- (instancetype)initWithPreviousValue:(nullable NSDate *)previousValue;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
///
/// @return An initialized instance.
///
- (instancetype)initDefault;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `SharedContentRemoveLinkExpiryDetails`
/// struct.
///
@interface DBTEAMLOGSharedContentRemoveLinkExpiryDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGSharedContentRemoveLinkExpiryDetails` instances.
///
/// @param instance An instance of the
/// `DBTEAMLOGSharedContentRemoveLinkExpiryDetails` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGSharedContentRemoveLinkExpiryDetails` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGSharedContentRemoveLinkExpiryDetails *)instance;

///
/// Deserializes `DBTEAMLOGSharedContentRemoveLinkExpiryDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGSharedContentRemoveLinkExpiryDetails` API object.
///
/// @return An instantiation of the
/// `DBTEAMLOGSharedContentRemoveLinkExpiryDetails` object.
///
+ (DBTEAMLOGSharedContentRemoveLinkExpiryDetails *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
