/**
 *  Copyright 2012 Neurowork Consulting S.L.
 *
 *  This file is part of eMobc.
 *
 *  eMobcViewController.m
 *  eMobc IOS Framework
 *
 *  eMobc is free software: you can redistribute it and/or modify
 *  it under the terms of the Affero GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  eMobc is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the Affero GNU General Public License
 *  along with eMobc.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "BSForwardGeocoder.h"
#import "MapLevelData.h"
#import "NwController.h"
#import "NearUtil.h"

#import "AppStyles.h"
#import "AppFormatsStyles.h"

/**
 * CLASS SUMMARY
 * NwMapController is map viewController so It is going to handle map view
 *
 * @note NwMapController need data to work, this dates is taken from map.xml and then saves into data.
 * @note mapController to handle in a correct way this view we doesn't just use our logic, we use a extern libray
 * which has to handle all logic to handle everything abuout map called BSForwardGeocoder
 */

@class eMobcViewController;

@interface NwMapController : NwController <MKReverseGeocoderDelegate, MKMapViewDelegate, BSForwardGeocoderDelegate, UISearchBarDelegate>{
	
//Objetos
	BSForwardGeocoder* forwardGeocoder;	//lib necesary to handle the map
	MapLevelData* data;
	NSMutableArray* annotations;
	NSMutableArray *copyListOfItems;
	MapItem* itemToGo;
	
	AppStyles* varStyles;
	AppFormatsStyles* varFormats;
	UIImageView *background;
	
//Outlets
	IBOutlet UISearchBar *searchBar;
	MKMapView *mapView;
	
	UIDeviceOrientation currentOrientation;
	
	bool loadContent;
	
	NSInteger sizeTop;
	NSInteger sizeBottom;
	NSInteger sizeHeaderText;
	
	UIButton *nearPosButton;
	UIImageView *imageSize;
} 

@property(nonatomic, retain) MKMapView *mapView;
@property(nonatomic, retain) MapLevelData* data;
@property(nonatomic, retain) MapItem* itemToGo;
@property(nonatomic, retain) NSMutableArray* annotations;

@property(nonatomic, retain) AppStyles* varStyles;
@property(nonatomic, retain) AppFormatsStyles* varFormats;
@property(nonatomic, retain) UIImageView *background;

@property (nonatomic) NSInteger sizeTop;
@property (nonatomic) NSInteger sizeBottom;
@property (nonatomic) NSInteger sizeHeaderText;

@property(nonatomic, retain) UIButton *nearPosButton;
@property (nonatomic, retain) UIImageView *imageSize;

//Acciones
	-(IBAction) back:(id)sender;
	-(IBAction) findUserPos:(id)sender;
	-(IBAction) nearPositions:(id)sender;


//Metodos
	-(void) searchAddress;
	-(void) loadMapItems;
	-(void) goToItem;
	-(void) loadMapa;
	-(void) createMapView;
	-(void) createButtonNear;

	-(void) loadThemesComponents;
	-(void) loadThemes;

NSComparisonResult compareDistance(NearUtil* first, NearUtil *second, void *context);

@end