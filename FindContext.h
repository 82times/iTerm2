//
//  FindContext.h
//  iTerm
//
//  Created by George Nachman on 10/26/13.
//
//

#import <Foundation/Foundation.h>

#define FindOptCaseInsensitive (1 << 0)
#define FindOptBackwards       (1 << 1)
#define FindOptRegex           (1 << 2)
#define FindMultipleResults    (1 << 3)

typedef enum {
    Searching,
    Matched,
    NotFound
} FindContextStatus;

@interface FindContext : NSObject {
    int absBlockNum_;
    NSString* substring_;
    int options_;
    int dir_;
    int offset_;
    int stopAt_;
    FindContextStatus status_;
    int matchLength_;
    NSMutableArray* results_;
    BOOL hasWrapped_;
    NSTimeInterval maxTime_;
};

// Current absolute block number being searched.
@property(nonatomic, assign) int absBlockNum;

// The substring to search for.
@property(nonatomic, copy) NSString *substring;

// A bitwise OR of the options defined above.
@property(nonatomic, assign) int options;

// 1: search forward. -1: search backward.
@property(nonatomic, assign) int dir;

// The offset within a block to begin searching. -1 means the end of the
// block.
@property(nonatomic, assign) int offset;

// The offset within a block at which to stop searching. No results
// with an offset at or beyond this position will be returned.
@property(nonatomic, assign) int stopAt;

// Searching: a search is in progress and this context can be used to search.
// Matched: At least one result has been found. This context can be used to
//   search again.
// NotFound: No results were found and the end of the buffer was reached.
@property(nonatomic, assign) FindContextStatus status;
@property(nonatomic, assign) int matchLength;

// used for multiple results
@property(nonatomic, retain) NSMutableArray *results;

// for client use. Not read or written by LineBuffer.
@property(nonatomic, assign) BOOL hasWrapped;

@property(nonatomic, assign) NSTimeInterval maxTime;

- (void)copyFromFindContext:(FindContext *)other;

- (void)reset;

@end