///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGTfaRemoveSecurityKeyDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `TfaRemoveSecurityKeyDetails` struct.
///
/// Removed security key for two-step verification.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGTfaRemoveSecurityKeyDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @return An initialized instance.
///
- (instancetype)initDefault;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `TfaRemoveSecurityKeyDetails` struct.
///
@interface DBTEAMLOGTfaRemoveSecurityKeyDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGTfaRemoveSecurityKeyDetails` instances.
///
/// @param instance An instance of the `DBTEAMLOGTfaRemoveSecurityKeyDetails`
/// API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGTfaRemoveSecurityKeyDetails` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGTfaRemoveSecurityKeyDetails *)instance;

///
/// Deserializes `DBTEAMLOGTfaRemoveSecurityKeyDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGTfaRemoveSecurityKeyDetails` API object.
///
/// @return An instantiation of the `DBTEAMLOGTfaRemoveSecurityKeyDetails`
/// object.
///
+ (DBTEAMLOGTfaRemoveSecurityKeyDetails *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
