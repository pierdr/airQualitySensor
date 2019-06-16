///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import "DBAUTHUserAuthRoutes.h"
#import "DBFILEPROPERTIESUserAuthRoutes.h"
#import "DBFILEREQUESTSUserAuthRoutes.h"
#import "DBFILESUserAuthRoutes.h"
#import "DBPAPERUserAuthRoutes.h"
#import "DBRequestErrors.h"
#import "DBSHARINGUserAuthRoutes.h"
#import "DBTasks.h"
#import "DBUSERSUserAuthRoutes.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DBTransportClient;

///
/// Base client object that contains an instance field for each namespace, each
/// of which contains references to all routes within that namespace.
/// Fully-implemented API clients will inherit this class.
///
@interface DBUserBaseClient : NSObject {

@protected
  id<DBTransportClient> _transportClient;
}

/// Routes within the `auth` namespace.
@property (nonatomic, readonly) DBAUTHUserAuthRoutes *authRoutes;

/// Routes within the `fileProperties` namespace.
@property (nonatomic, readonly) DBFILEPROPERTIESUserAuthRoutes *filePropertiesRoutes;

/// Routes within the `fileRequests` namespace.
@property (nonatomic, readonly) DBFILEREQUESTSUserAuthRoutes *fileRequestsRoutes;

/// Routes within the `files` namespace.
@property (nonatomic, readonly) DBFILESUserAuthRoutes *filesRoutes;

/// Routes within the `paper` namespace.
@property (nonatomic, readonly) DBPAPERUserAuthRoutes *paperRoutes;

/// Routes within the `sharing` namespace.
@property (nonatomic, readonly) DBSHARINGUserAuthRoutes *sharingRoutes;

/// Routes within the `users` namespace.
@property (nonatomic, readonly) DBUSERSUserAuthRoutes *usersRoutes;

/// Initializes the `DBUserBaseClient` object with a networking client.
- (instancetype)initWithTransportClient:(id<DBTransportClient>)client;

@end

NS_ASSUME_NONNULL_END