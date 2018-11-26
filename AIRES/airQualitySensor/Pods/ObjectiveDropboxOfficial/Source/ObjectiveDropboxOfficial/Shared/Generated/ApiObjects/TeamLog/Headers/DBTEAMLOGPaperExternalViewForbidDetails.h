///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGPaperExternalViewForbidDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `PaperExternalViewForbidDetails` struct.
///
/// Changed Paper external sharing setting to team-only.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGPaperExternalViewForbidDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// Event unique identifier.
@property (nonatomic, readonly, copy) NSString *eventUuid;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param eventUuid Event unique identifier.
///
/// @return An initialized instance.
///
- (instancetype)initWithEventUuid:(NSString *)eventUuid;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `PaperExternalViewForbidDetails` struct.
///
@interface DBTEAMLOGPaperExternalViewForbidDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGPaperExternalViewForbidDetails` instances.
///
/// @param instance An instance of the `DBTEAMLOGPaperExternalViewForbidDetails`
/// API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGPaperExternalViewForbidDetails` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGPaperExternalViewForbidDetails *)instance;

///
/// Deserializes `DBTEAMLOGPaperExternalViewForbidDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGPaperExternalViewForbidDetails` API object.
///
/// @return An instantiation of the `DBTEAMLOGPaperExternalViewForbidDetails`
/// object.
///
+ (DBTEAMLOGPaperExternalViewForbidDetails *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
