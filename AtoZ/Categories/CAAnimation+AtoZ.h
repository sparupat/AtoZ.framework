
//  CAAnimation+AtoZ.h
//  AtoZ
#import <QuartzCore/QuartzCore.h>
//  Created by Alex Gray on 7/13/12.
//  Copyright (c) 2012 mrgray.com, inc. All rights reserved.

typedef void (^AZCAAnimationCompletionBlock)();

//Note this is slightly flawed as we set ourself as the delegate, really we should create a chained proxy, if we need that I will add it.
//@interface CATransaction (AtoZ)
//+ (void)CADisabledBlock:(void(^)(void))block;
//@end

////typedef void (^disableCA) {
//- (NSArray *)setPropertiesWithCADisabled:(BOOL (^)(id obj))block		{
//		NSMutableArray * results = NSMA.new;
//		[self each:^(id obj, NSUInteger index, BOOL *stop) {
//			if (block(obj))		[results addObject:obj];
//		}];
//		return results;
//	}
//	[CATransaction flush];  [CATransaction begin];
//	[CATransaction setValue:@(YES) forKey:kCATransactionDisableActions];
//}


@interface CAAnimation (BlocksAddition)

@property (nonatomic, copy) void (^completion)(BOOL finished);
@property (nonatomic, copy) void (^start)(void);

- (void)setCompletion:(void (^)(BOOL finished))completion; // Forces auto-complete of setCompletion: to add the name 'finished' in the block parameter

@end


extern void disableCA();
@interface CAKeyframeAnimation (JumpingAndShaking)

+ (CAKeyframeAnimation *)shakeAnimation:(NSRect)frame;
+ (CAKeyframeAnimation *)jumpAnimation;
+ (CAKeyframeAnimation *)dockBounceAnimationWithIconHeight:(CGFloat)iconHeight;

@end

@interface CAAnimation (AtoZ)

+ (CABA*) animationWithKeyPath: (NSS*)path andDuration:(NSTI)interval;
+ (CABA*) propertyAnimation: (NSD*) dict;

+ (CAAnimation*)randomPathAnimationWithStartingPoint:(CGPoint)firstPoint inFrame:(NSR)rect;
+ (CAAnimation*)randomPathAnimationInFrame:(NSRect) frame;

+ (CAKA*)		   popInAnimation;
+ (CAAG*)   shrinkAnimationAtPoint: (CGPoint)p;
+ (CAAG*)   blowupAnimationAtPoint: (CGPoint)p;
+ (CAA*)			shakeAnimation;
+ (CAA*)	   animationForOpacity;
//+ (CAA*)		 animationForScale;
//+ (CAA*)	  animationForRotation;
//+ (CAA*) flipAnimationWithDuration: (NSTI)aDur;
+ (CAA*)				  flipDown: (NSTI)aDur  scaleFactor: (CGF)scale;
+ (CAA*) 		   animationOnPath: (CGPR)path  duration:	(CFTI)d 	  timeOffset: (CFTI)o;
//+ (CAA*)	colorAnimationForLayer: (CAL*)layer start:	   (NSC*)c1  	  end: (NSC*)c2;
+ (CAA*)   rotateAnimationForLayer: (CAL*)layer start:	   (CGF)fl1	 end: (CGF)fl1;


//- (CAAnimation *)rotateAnimationFrom:(NSNumber*)startDegree to:(NSNumber*)endDegrees;
+ (CAAnimation*)rotateAnimationForLayer:(CALayer *)theLayer start:(CGFloat)starting end:(CGFloat)ending;
+ (CAAnimation*)colorAnimationForLayer:(CALayer *)theLayer WithStartingColor:(NSColor*)color1 endColor:(NSColor*)color2;

@property (NATOM, CP) AZCAAnimationCompletionBlock az_completionBlock;

@end

@interface NSView (CAAnimationEGOHelper)
- (void)popInAnimated;
@end
@interface CALayer (CAAnimationEGOHelper)
- (void)popInAnimated;
@end

@interface CATransition (AtoZ)

+ (CATransition*) randomTransition;
+ (NSA*)transitionsFor:(id)targetView;

@end

