//
//  GJGCChatInputPanel.h
//  ZYChat
//
//  Created by ZYVincent QQ:1003081775 on 14-10-28.
//  Copyright (c) 2014年 ZYProSoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GJGCChatInputBar.h"
#import "GJGCChatInputConst.h"
#import "GJGCChatInputExpandMenuPanelConfigModel.h"
#import "GJGCChatInputPanelDelegate.h"
#import "GJGCChatInputExpandEmojiPanel.h"
#import "GJGCChatInputExpandMenuPanel.h"

@class GJGCChatInputPanel;

typedef void (^GJGCChatInputPanelKeyboardFrameChangeBlock) (GJGCChatInputPanel *panel,CGRect keyboardBeginFrame,CGRect keyboardEndFrame,NSTimeInterval duration,BOOL isPanelReserve);

typedef void (^GJGCChatInputPanelRecordStateChangeBlock) (GJGCChatInputPanel *panel,BOOL isRecording);

typedef void (^GJGCChatInputPanelInputTextViewHeightChangedBlock) (GJGCChatInputPanel *panel,CGFloat changeDelta);

@interface GJGCChatInputPanel : UIView

@property (nonatomic,weak)id<GJGCChatInputPanelDelegate> delegate;

@property (nonatomic,readonly)NSString *messageDraft;

@property (nonatomic,copy)GJGCChatInputBarDidChangeActionBlock actionChangeBlock;

@property (nonatomic,copy)GJGCChatInputPanelRecordStateChangeBlock recordStateChangeBlock;

@property (nonatomic,assign)BOOL isFullState;

@property (nonatomic,assign)CGFloat inputBarHeight;

@property (nonatomic,readonly)GJGCChatInputBarActionType currentActionType;

@property (nonatomic,assign)GJGCChatInputBarActionType disableActionType;

@property (nonatomic,readonly)NSString *panelIndentifier;

@property (nonatomic,strong)NSString *inputBarTextViewPlaceHolder;

- (instancetype)initWithPanelDelegate:(id<GJGCChatInputPanelDelegate>)aDelegate;

- (instancetype)initForCommentBarWithPanelDelegate:(id<GJGCChatInputPanelDelegate>)aDelegate;

- (void)configInputPanelKeyboardFrameChange:(GJGCChatInputPanelKeyboardFrameChangeBlock)changeBlock;

- (void)configInputPanelRecordStateChange:(GJGCChatInputPanelRecordStateChangeBlock)recordChangeBlock;

- (void)configInputPanelInputTextViewHeightChangedBlock:(GJGCChatInputPanelInputTextViewHeightChangedBlock)heightChangeBlock;

- (void)reserveState;

- (void)reserveCommentState;

- (void)recordRightStartLimit;

- (BOOL)isInputTextFirstResponse;

- (void)becomeFirstResponse;

- (void)inputBarRegsionFirstResponse;

- (void)setLastMessageDraft:(NSString *)msgDraft;

- (void)startKeyboardObserve;

- (void)removeKeyboardObserve;

- (void)appendFocusOnOther:(NSString *)otherName;

@end
