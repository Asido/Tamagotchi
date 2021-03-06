//
//  EAGLView.h
//  Tamagotchi
//
//  Created by st on 11/06/2013.
//  Copyright (c) 2013 Asido. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

@interface EAGLView : UIView
{
@private
    // The pixel dimensions of the backbuffer.
    GLint backingWidth;
    GLint backingHeight;
    
    EAGLContext *context;
    
    // OpenGL names for the renderbuffer and framebuffers used to render to this view.
    GLuint viewRenderbuffer, viewFramebuffer;
    
    // OpenGL name for the depth buffer that is attached to viewFramebuffer, if it exists (0 if it doesn't exist).
    GLuint depthRenderbuffer;
    
    NSTimer         *renderTimer;
    NSTimeInterval  renderInterval;
}

@property (assign, nonatomic) NSTimeInterval renderInterval;

- (void)startRendering;
- (void)stopRendering;
- (void)renderView;

@end
