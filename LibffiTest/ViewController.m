//
//  ViewController.m
//  LibffiTest
//
//  Created by Teodor Dermendzhiev on 16/02/2018.
//  Copyright © 2018 Teodor Dermendzhiev. All rights reserved.
//

#import "ViewController.h"
#import "FFICall.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    callFFI();
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
