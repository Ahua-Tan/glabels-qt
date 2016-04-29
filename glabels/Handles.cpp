/*  Handles.cpp
 *
 *  Copyright (C) 2013  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Handles.h"


#include "LabelModelObject.h"

#include <QColor>
#include <QtDebug>


namespace
{
	const double handlePixels             = 7;
	const double handleOutlineWidthPixels = 1;

	const QColor handleFillColor( 0,  192,  0,  96 );
	const QColor originHandleFillColor( 192,  0,  0,  96 );
	const QColor handleOutlineColor( 0,  0,   0,  192 );
}


///
/// Handle Constructor
///
Handle::Handle( LabelModelObject* owner, Location location )
	: mOwner(owner), mLocation(location)
{
}


///
/// Handle Destructor
///
Handle::~Handle()
{
}


///
/// Handle owner
///
LabelModelObject* Handle::owner() const
{
	return mOwner;
}


///
/// Handle location
///
Handle::Location Handle::location() const
{
	return mLocation;
}


///
/// Draw Handle at x,y
///
void Handle::drawAt( QPainter*                painter,
		     double                   scale,
		     const glabels::Distance& x,
		     const glabels::Distance& y,
		     QColor                   color ) const
{
	painter->save();

	painter->translate( x.pt(), y.pt() );

	double s = 1.0 / scale;

	QPen pen( handleOutlineColor );
	pen.setCosmetic( true );
	pen.setWidth( handleOutlineWidthPixels );

	painter->setPen( pen );
	painter->setBrush( color );

	painter->drawRect( QRectF( -s*handlePixels/2.0, -s*handlePixels/2.0, s*handlePixels, s*handlePixels ) );

	painter->restore();
}


///
/// Create Handle path at x,y
///
QPainterPath Handle::pathAt( double                   scale,
			     const glabels::Distance& x,
			     const glabels::Distance& y ) const
{
	QPainterPath path;

	double s = 1/scale;

	path.addRect( -s*handlePixels/2, -s*handlePixels/2, s*handlePixels, s*handlePixels );
	path.translate( x.pt(), y.pt() );
	
	return path;
}


///
/// HandleNorth Constructor
///
HandleNorth::HandleNorth( LabelModelObject* owner )
	: Handle( owner, N )
{
}


///
/// HandleNorth Destructor
///
HandleNorth::~HandleNorth()
{
}


///
/// HandleNorth Clone
///
HandleNorth* HandleNorth::clone( LabelModelObject* newOwner ) const
{
	return new HandleNorth( newOwner );
}


///
/// Draw HandleNorth
///
void HandleNorth::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, mOwner->w()/2, 0, handleFillColor );
}


///
/// HandleNorth Path
///
QPainterPath HandleNorth::path( double scale ) const
{
	return pathAt( scale, mOwner->w()/2, 0 );
}


///
/// HandleNorthEast Constructor
///
HandleNorthEast::HandleNorthEast( LabelModelObject* owner )
	: Handle( owner, NE )
{
}


///
/// HandleNorthEast Destructor
///
HandleNorthEast::~HandleNorthEast()
{
}


///
/// HandleNorthEast Clone
///
HandleNorthEast* HandleNorthEast::clone( LabelModelObject* newOwner ) const
{
	return new HandleNorthEast( newOwner );
}


///
/// Draw HandleNorthEast
///
void HandleNorthEast::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, mOwner->w(), 0, handleFillColor );
}


///
/// HandleNorthEast Path
///
QPainterPath HandleNorthEast::path( double scale ) const
{
	return pathAt( scale, mOwner->w(), 0 );
}


///
/// HandleEast Constructor
///
HandleEast::HandleEast( LabelModelObject* owner )
	: Handle( owner, E )
{
}


///
/// HandleEast Destructor
///
HandleEast::~HandleEast()
{
}


///
/// HandleEast Clone
///
HandleEast* HandleEast::clone( LabelModelObject* newOwner ) const
{
	return new HandleEast( newOwner );
}


///
/// Draw HandleEast
///
void HandleEast::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, mOwner->w(), mOwner->h()/2, handleFillColor );
}


///
/// HandleEast Path
///
QPainterPath HandleEast::path( double scale ) const
{
	return pathAt( scale, mOwner->w(), mOwner->h()/2 );
}


///
/// HandleSouthEast Constructor
///
HandleSouthEast::HandleSouthEast( LabelModelObject* owner )
	: Handle( owner, SE )
{
}


///
/// HandleSouthEast Destructor
///
HandleSouthEast::~HandleSouthEast()
{
}


///
/// HandleSouthEast Clone
///
HandleSouthEast* HandleSouthEast::clone( LabelModelObject* newOwner ) const
{
	return new HandleSouthEast( newOwner );
}


///
/// Draw HandleSouthEast
///
void HandleSouthEast::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, mOwner->w(), mOwner->h(), handleFillColor );
}


///
/// HandleSouthEast Path
///
QPainterPath HandleSouthEast::path( double scale ) const
{
	return pathAt( scale, mOwner->w(), mOwner->h() );
}


///
/// HandleSouth Constructor
///
HandleSouth::HandleSouth( LabelModelObject* owner )
	: Handle( owner, S )
{
}


///
/// HandleSouth Destructor
///
HandleSouth::~HandleSouth()
{
}


///
/// HandleSouth Clone
///
HandleSouth* HandleSouth::clone( LabelModelObject* newOwner ) const
{
	return new HandleSouth( newOwner );
}


///
/// Draw HandleSouth
///
void HandleSouth::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, mOwner->w()/2, mOwner->h(), handleFillColor );
}


///
/// HandleSouth Path
///
QPainterPath HandleSouth::path( double scale ) const
{
	return pathAt( scale, mOwner->w()/2, mOwner->h() );
}


///
/// HandleSouthWest Constructor
///
HandleSouthWest::HandleSouthWest( LabelModelObject* owner )
	: Handle( owner, SW )
{
}


///
/// HandleSouthWest Destructor
///
HandleSouthWest::~HandleSouthWest()
{
}


///
/// HandleSouthWest Clone
///
HandleSouthWest* HandleSouthWest::clone( LabelModelObject* newOwner ) const
{
	return new HandleSouthWest( newOwner );
}


///
/// Draw HandleSouthWest
///
void HandleSouthWest::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, 0, mOwner->h(), handleFillColor );
}


///
/// HandleSouthWest Path
///
QPainterPath HandleSouthWest::path( double scale ) const
{
	return pathAt( scale, 0, mOwner->h() );
}


///
/// HandleWest Constructor
///
HandleWest::HandleWest( LabelModelObject* owner )
	: Handle( owner, W )
{
}


///
/// HandleWest Destructor
///
HandleWest::~HandleWest()
{
}


///
/// HandleWest Clone
///
HandleWest* HandleWest::clone( LabelModelObject* newOwner ) const
{
	return new HandleWest( newOwner );
}


///
/// Draw HandleWest
///
void HandleWest::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, 0, mOwner->h()/2, handleFillColor );
}


///
/// HandleWest Path
///
QPainterPath HandleWest::path( double scale ) const
{
	return pathAt( scale, 0, mOwner->h()/2 );
}


///
/// HandleNorthWest Constructor
///
HandleNorthWest::HandleNorthWest( LabelModelObject* owner )
	: Handle( owner, NW )
{
}


///
/// HandleNorthWest Destructor
///
HandleNorthWest::~HandleNorthWest()
{
}

///
/// HandleNorthWest Clone
///
HandleNorthWest* HandleNorthWest::clone( LabelModelObject* newOwner ) const
{
	return new HandleNorthWest( newOwner );
}


///
/// Draw HandleNorthWest
///
void HandleNorthWest::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, 0, 0, originHandleFillColor );
}


///
/// HandleNorthWest Path
///
QPainterPath HandleNorthWest::path( double scale ) const
{
	return pathAt( scale, 0, 0 );
}


///
/// HandleP1 Constructor
///
HandleP1::HandleP1( LabelModelObject* owner )
	: Handle( owner, P1 )
{
}


///
/// HandleP1 Destructor
///
HandleP1::~HandleP1()
{
}


///
/// HandleP1 Clone
///
HandleP1* HandleP1::clone( LabelModelObject* newOwner ) const
{
	return new HandleP1( newOwner );
}


///
/// Draw HandleP1
///
void HandleP1::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, 0, 0, originHandleFillColor );
}


///
/// HandleP1 Path
///
QPainterPath HandleP1::path( double scale ) const
{
	return pathAt( scale, 0, 0 );
}


///
/// HandleP2 Constructor
///
HandleP2::HandleP2( LabelModelObject* owner )
	: Handle( owner, P2 )
{
}


///
/// HandleP2 Destructor
///
HandleP2::~HandleP2()
{
}


///
/// HandleP2 Clone
///
HandleP2* HandleP2::clone( LabelModelObject* newOwner ) const
{
	return new HandleP2( newOwner );
}


///
/// Draw HandleP2
///
void HandleP2::draw( QPainter* painter, double scale ) const
{
	drawAt( painter, scale, mOwner->w(), mOwner->h(), handleFillColor );
}


///
/// HandleP2 Path
///
QPainterPath HandleP2::path( double scale ) const
{
	return pathAt( scale, mOwner->w(), mOwner->h() );
}
