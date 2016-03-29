//
//  IDMZoomingScrollView.h
//  IDMPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDMPhotoProtocol.h"
#import "IDMTapDetectingImageView.h"
#import "IDMTapDetectingView.h"

#import <DACircularProgress/DACircularProgressView.h>

//@class IDMPhotoBrowser, IDMPhoto, IDMCaptionView;
@class IDMPhoto, IDMCaptionView;

@protocol IDMZoomingScrollViewDelegate;

@interface IDMZoomingScrollView : UIScrollView <UIScrollViewDelegate, IDMTapDetectingImageViewDelegate, IDMTapDetectingViewDelegate> {
	
//	IDMPhotoBrowser *__weak _photoBrowser;
    id<IDMPhoto> _photo;
	
    // This view references the related caption view for simplified handling in photo browser
    IDMCaptionView *_captionView;
    
	IDMTapDetectingView *_tapView; // for background taps
    
    DACircularProgressView *_progressView;
}

@property (nonatomic, strong) IDMTapDetectingImageView *photoImageView;
@property (nonatomic, strong) IDMCaptionView *captionView;
@property (nonatomic, strong) id<IDMPhoto> photo;

//- (id)initWithPhotoBrowser:(IDMPhotoBrowser *)browser;
- (id)initWithPhotoDelegate:(id<IDMZoomingScrollViewDelegate>)photoDelegate;
- (void)displayImage;
- (void)displayImageFailure;
- (void)setProgress:(CGFloat)progress forPhoto:(IDMPhoto*)photo;
- (void)setMaxMinZoomScalesForCurrentBounds;
- (void)prepareForReuse;

@end

@protocol IDMZoomingScrollViewDelegate <NSObject>

@required
- (UIImage *)imageForPhoto:(id<IDMPhoto>)photo zoomingScrollView:(IDMZoomingScrollView *)zoomingScrollView;

@optional
- (UIColor *)trackTintColorForZoomingScrollView:(IDMZoomingScrollView *)zoomingScrollView;
- (UIColor *)progressTintColorForZoomingScrollView:(IDMZoomingScrollView *)zoomingScrollView;

- (void)handleSingleTap:(CGPoint)touchPoint zoomingScrollView:(IDMZoomingScrollView *)zoomingScrollView;
- (void)handleDoubleTap:(CGPoint)touchPoint zoomingScrollView:(IDMZoomingScrollView *)zoomingScrollView;
- (void)handleLongTapInZoomingScrollView:(IDMZoomingScrollView *)zoomingScrollView;

@end
