/***************************************************************************
    qgscacheindex.h
     --------------------------------------
    Date                 : 13.2.2013
    Copyright            : (C) 2013 Matthias Kuhn
    Email                : matthias at opengis dot ch
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSCACHEINDEX_H
#define QGSCACHEINDEX_H

#include "qgsfeature.h" // QgsFeatureIds

class QgsFeatureRequest;
class QgsFeatureIterator;

/**
 * @brief
 * Abstract base class for cache indices
 */

class CORE_EXPORT QgsAbstractCacheIndex
{
  public:
    QgsAbstractCacheIndex();
    virtual ~QgsAbstractCacheIndex();

    /**
     * Is called, whenever a feature is removed from the cache. You should update your indexes, so
     * they become invalid in case this feature was required to successfuly answer a request.
     */
    virtual void flushFeature( const QgsFeatureId fid ) = 0;

    /**
     * Sometimes, the whole cache changes its state and its easier to just withdraw everything.
     * In this case, this method is issued. Be sure to clear all cache information in here.
     */
    virtual void flush() = 0;

    /**
     * @brief
     * Implement this method to update the the indices, in case you need information contained by the request
     * to properly index. (E.g. spatial index)
     * Does nothing by default
     *
     * @param featureRequest  The feature request that was answered
     * @param fids            The feature ids that have been returned
     */
    virtual void requestCompleted( const QgsFeatureRequest& featureRequest, const QgsFeatureIds& fids );

    /**
     * Is called, when a feature request is issued on a cached layer.
     * If this cache index is able to completely answer the feature request, it will return true
     * and write the list of feature ids of cached features to cachedFeatures. If it is not able
     * it will return false and the cachedFeatures state is undefined.
     *
     * @param featureIterator  A reference to a {@link QgsFeatureIterator}. A valid featureIterator will
     *                         be assigned in case this index is able to answer the request and the return
     *                         value is true.
     * @param featureRequest   The feature request, for which this index is queried.
     *
     * @return   True, if this index holds the information to answer the request.
     *
     */
    virtual bool getCacheIterator( QgsFeatureIterator& featureIterator, const QgsFeatureRequest& featureRequest ) = 0;
};

#endif // QGSCACHEINDEX_H
