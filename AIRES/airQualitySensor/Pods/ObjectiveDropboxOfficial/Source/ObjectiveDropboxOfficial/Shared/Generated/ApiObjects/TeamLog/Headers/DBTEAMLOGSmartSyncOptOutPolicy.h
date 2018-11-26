///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGSmartSyncOptOutPolicy;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SmartSyncOptOutPolicy` union.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGSmartSyncOptOutPolicy : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMLOGSmartSyncOptOutPolicyTag` enum type represents the possible
/// tag states with which the `DBTEAMLOGSmartSyncOptOutPolicy` union can exist.
typedef NS_ENUM(NSInteger, DBTEAMLOGSmartSyncOptOutPolicyTag) {
  /// (no description).
  DBTEAMLOGSmartSyncOptOutPolicyDefault_,

  /// (no description).
  DBTEAMLOGSmartSyncOptOutPolicyOptedOut,

  /// (no description).
  DBTEAMLOGSmartSyncOptOutPolicyOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMLOGSmartSyncOptOutPolicyTag tag;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "default".
///
/// @return An initialized instance.
///
- (instancetype)initWithDefault_;

///
/// Initializes union class with tag state of "opted_out".
///
/// @return An initialized instance.
///
- (instancetype)initWithOptedOut;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "default".
///
/// @return Whether the union's current tag state has value "default".
///
- (BOOL)isDefault_;

///
/// Retrieves whether the union's current tag state has value "opted_out".
///
/// @return Whether the union's current tag state has value "opted_out".
///
- (BOOL)isOptedOut;

///
/// Retrieves whether the union's current tag state has value "other".
///
/// @return Whether the union's current tag state has value "other".
///
- (BOOL)isOther;

///
/// Retrieves string value of union's current tag state.
///
/// @return A human-readable string representing the union's current tag state.
///
- (NSString *)tagName;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `DBTEAMLOGSmartSyncOptOutPolicy` union.
///
@interface DBTEAMLOGSmartSyncOptOutPolicySerializer : NSObject

///
/// Serializes `DBTEAMLOGSmartSyncOptOutPolicy` instances.
///
/// @param instance An instance of the `DBTEAMLOGSmartSyncOptOutPolicy` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGSmartSyncOptOutPolicy` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGSmartSyncOptOutPolicy *)instance;

///
/// Deserializes `DBTEAMLOGSmartSyncOptOutPolicy` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGSmartSyncOptOutPolicy` API object.
///
/// @return An instantiation of the `DBTEAMLOGSmartSyncOptOutPolicy` object.
///
+ (DBTEAMLOGSmartSyncOptOutPolicy *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
