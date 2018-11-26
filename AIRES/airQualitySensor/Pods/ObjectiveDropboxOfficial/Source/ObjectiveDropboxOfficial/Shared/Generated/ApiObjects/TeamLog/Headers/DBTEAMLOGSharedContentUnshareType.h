///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGSharedContentUnshareType;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SharedContentUnshareType` struct.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGSharedContentUnshareType : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// (no description).
@property (nonatomic, readonly, copy) NSString *description_;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param description_ (no description).
///
/// @return An initialized instance.
///
- (instancetype)initWithDescription_:(NSString *)description_;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `SharedContentUnshareType` struct.
///
@interface DBTEAMLOGSharedContentUnshareTypeSerializer : NSObject

///
/// Serializes `DBTEAMLOGSharedContentUnshareType` instances.
///
/// @param instance An instance of the `DBTEAMLOGSharedContentUnshareType` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGSharedContentUnshareType` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGSharedContentUnshareType *)instance;

///
/// Deserializes `DBTEAMLOGSharedContentUnshareType` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGSharedContentUnshareType` API object.
///
/// @return An instantiation of the `DBTEAMLOGSharedContentUnshareType` object.
///
+ (DBTEAMLOGSharedContentUnshareType *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
