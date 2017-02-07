/***************************************************************************
 *  qgsgeometrysnapperplugin.cpp                                           *
 *  -------------------                                                    *
 *  copyright            : (C) 2014 by Sandro Mani / Sourcepole AG         *
 *  email                : smani@sourcepole.ch                             *
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgsgeometrysnapperplugin.h"
#include "qgisinterface.h"

QgsGeometrySnapperPlugin::QgsGeometrySnapperPlugin( QgisInterface* iface )
    : QgisPlugin( sName, sDescription, sCategory, sPluginVersion, sPluginType )
    , mIface( iface )
    , mDialog( nullptr )
    , mMenuAction( nullptr )
{
}

void QgsGeometrySnapperPlugin::initGui()
{
  mDialog = new QgsGeometrySnapperDialog( mIface );
  mMenuAction = new QAction( QIcon( ":/geometrysnapper/icons/geometrysnapper.png" ), QApplication::translate( "QgsGeometrySnapperPlugin", "Snap geometries" ), this );
  connect( mMenuAction, SIGNAL( triggered() ), mDialog, SLOT( show() ) );
  mIface->addPluginToVectorMenu( QApplication::translate( "QgsGeometrySnapperPlugin", "G&eometry Tools" ), mMenuAction );
}

void QgsGeometrySnapperPlugin::unload()
{
  delete mDialog;
  mDialog = nullptr;
  delete mMenuAction;
  mMenuAction = nullptr;
  mIface->removePluginVectorMenu( QApplication::translate( "QgsGeometrySnapperPlugin", "G&eometry Tools" ), mMenuAction );
}


//////////////////////////////////////////////////////////////////////////
//
//
//  THE FOLLOWING CODE IS AUTOGENERATED BY THE PLUGIN BUILDER SCRIPT
//    YOU WOULD NORMALLY NOT NEED TO MODIFY THIS, AND YOUR PLUGIN
//      MAY NOT WORK PROPERLY IF YOU MODIFY THIS INCORRECTLY
//
//
//////////////////////////////////////////////////////////////////////////


/**
 * Required extern functions needed  for every plugin
 * These functions can be called prior to creating an instance
 * of the plugin class
 */
// Class factory to return a new instance of the plugin class
QGISEXTERN QgisPlugin * classFactory( QgisInterface * theQgisInterfacePointer )
{
  return new QgsGeometrySnapperPlugin( theQgisInterfacePointer );
}
// Return the name of the plugin - note that we do not user class members as
// the class may not yet be insantiated when this method is called.
QGISEXTERN QString name()
{
  return sName;
}

// Return the description
QGISEXTERN QString description()
{
  return sDescription;
}

// Return the category
QGISEXTERN QString category()
{
  return sCategory;
}

// Return the type (either UI or MapLayer plugin)
QGISEXTERN int type()
{
  return sPluginType;
}

// Return the version number for the plugin
QGISEXTERN QString version()
{
  return sPluginVersion;
}

QGISEXTERN QString icon()
{
  return sPluginIcon;
}

// Delete ourself
QGISEXTERN void unload( QgisPlugin * thePluginPointer )
{
  delete thePluginPointer;
}
