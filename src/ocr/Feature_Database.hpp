/**
 * @file Feature_Database.hpp
 *
 * @todo Add description
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   Nov 16, 2015
 *
 */

/*
 * Change Log:
 *
 * Nov 16, 2015: 
 * - Feature_Database.hpp created
 */
#ifndef OCR_FEATURE_DATABASE_HPP_
#define OCR_FEATURE_DATABASE_HPP_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include "Feature_Vector.hpp"
#include "Feature_Loader.hpp"
#include "Image.hpp"

#include <utility> // std::pair
#include <vector>  // std::vector
#include <cstddef> // std::size_t


namespace ocr {

  class Feature_Database  {

    //------------------------------------------------------------------------
    // Public Types
    //------------------------------------------------------------------------
  public:

    typedef std::pair<Image, feature_collection> cluster;
    typedef std::vector<cluster>                 cluster_collection;

    //------------------------------------------------------------------------
    // Constructor / Destructor
    //------------------------------------------------------------------------
  public:

    Feature_Database( );

    //------------------------------------------------------------------------
    // Capacity
    //------------------------------------------------------------------------
  public:

    std::size_t size() const;

    //------------------------------------------------------------------------
    // Access
    //------------------------------------------------------------------------
  public:

    Feature_Database& insert( const Image& data, feature_collection& vector );

    ///
    ///
    ///
    void analyze( Image& image, boundary_collection& bounds, feature_collection& features );

    //-----------------------------------------------------------------------------
    // Private Members
    //-----------------------------------------------------------------------------
  private:

    cluster_collection m_clusters;

  };

  inline std::size_t Feature_Database::size() const{
    return m_clusters.size();
  }

}  // namespace ocr



#endif /* OCR_FEATURE_DATABASE_HPP_ */
