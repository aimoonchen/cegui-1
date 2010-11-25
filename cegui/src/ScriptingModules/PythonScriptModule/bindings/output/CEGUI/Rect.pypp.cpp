// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "Rect.pypp.hpp"

namespace bp = boost::python;

void register_Rect_class(){

    { //::CEGUI::Rect
        typedef bp::class_< CEGUI::Rect > Rect_exposer_t;
        Rect_exposer_t Rect_exposer = Rect_exposer_t( "Rect", "*!\n\
        \n\
           Class encapsulating operations on a Rectangle\n\
        *\n", bp::init< >() );
        bp::scope Rect_scope( Rect_exposer );
        Rect_exposer.def( bp::init< float, float, float, float >(( bp::arg("left"), bp::arg("top"), bp::arg("right"), bp::arg("bottom") ), "*!\n\
        \n\
           Constructor for a Rect.\n\
        *\n") );
        Rect_exposer.def( bp::init< CEGUI::Vector2, CEGUI::Size >(( bp::arg("pos"), bp::arg("sz") )) );
        { //::CEGUI::Rect::constrainSize
        
            typedef ::CEGUI::Rect & ( ::CEGUI::Rect::*constrainSize_function_type )( ::CEGUI::Size const &,::CEGUI::Size const & ) ;
            
            Rect_exposer.def( 
                "constrainSize"
                , constrainSize_function_type( &::CEGUI::Rect::constrainSize )
                , ( bp::arg("max_sz"), bp::arg("min_sz") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
               \n\
                  check the size of the Rect object and if it is bigger than  max_sz or smaller than  min_sz,\
                  resize it so it isn't.\n\
            \n\
               @param max_sz\n\
                  Size object that describes the maximum dimensions that this Rect should be limited to.\n\
            \n\
               @param min_sz\n\
                  Size object that describes the minimum dimensions that this Rect should be limited to.\n\
            \n\
               @return\n\
                  'this' Rect object after the constrain operation\n\
               *\n" );
        
        }
        { //::CEGUI::Rect::constrainSizeMax
        
            typedef ::CEGUI::Rect & ( ::CEGUI::Rect::*constrainSizeMax_function_type )( ::CEGUI::Size const & ) ;
            
            Rect_exposer.def( 
                "constrainSizeMax"
                , constrainSizeMax_function_type( &::CEGUI::Rect::constrainSizeMax )
                , ( bp::arg("sz") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
               \n\
                  check the size of the Rect object and if it is bigger than  sz, resize it so it isn't.\n\
            \n\
               @param sz\n\
                  Size object that describes the maximum dimensions that this Rect should be limited to.\n\
            \n\
               @return\n\
                  'this' Rect object after the constrain operation\n\
               *\n" );
        
        }
        { //::CEGUI::Rect::constrainSizeMin
        
            typedef ::CEGUI::Rect & ( ::CEGUI::Rect::*constrainSizeMin_function_type )( ::CEGUI::Size const & ) ;
            
            Rect_exposer.def( 
                "constrainSizeMin"
                , constrainSizeMin_function_type( &::CEGUI::Rect::constrainSizeMin )
                , ( bp::arg("sz") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
               \n\
                  check the size of the Rect object and if it is smaller than  sz, resize it so it isn't.\n\
            \n\
               @param sz\n\
                  Size object that describes the minimum dimensions that this Rect should be limited to.\n\
            \n\
               @return\n\
                  'this' Rect object after the constrain operation\n\
               *\n" );
        
        }
        { //::CEGUI::Rect::getHeight
        
            typedef float ( ::CEGUI::Rect::*getHeight_function_type )(  ) const;
            
            Rect_exposer.def( 
                "getHeight"
                , getHeight_function_type( &::CEGUI::Rect::getHeight )
                , "*!\n\
            \n\
               return height of Rect area\n\
            *\n" );
        
        }
        { //::CEGUI::Rect::getIntersection
        
            typedef ::CEGUI::Rect ( ::CEGUI::Rect::*getIntersection_function_type )( ::CEGUI::Rect const & ) const;
            
            Rect_exposer.def( 
                "getIntersection"
                , getIntersection_function_type( &::CEGUI::Rect::getIntersection )
                , ( bp::arg("rect") )
                , "*!\n\
               \n\
                  return a Rect that is the intersection of 'this' Rect with the Rect 'rect'\n\
            \n\
               \note\n\
                  It can be assumed that if d_left == d_right, or d_top == d_bottom, or getWidth() == 0, or\
                  getHeight() == 0, then\n\
                  'this' rect was totally outside 'rect'.\n\
               *\n" );
        
        }
        { //::CEGUI::Rect::getPosition
        
            typedef ::CEGUI::Vector2 ( ::CEGUI::Rect::*getPosition_function_type )(  ) const;
            
            Rect_exposer.def( 
                "getPosition"
                , getPosition_function_type( &::CEGUI::Rect::getPosition )
                , "*!\n\
            \n\
               Return top-left postion of Rect as a Point\n\
            *\n" );
        
        }
        { //::CEGUI::Rect::getSize
        
            typedef ::CEGUI::Size ( ::CEGUI::Rect::*getSize_function_type )(  ) const;
            
            Rect_exposer.def( 
                "getSize"
                , getSize_function_type( &::CEGUI::Rect::getSize )
                , "*!\n\
            \n\
               return the size of the Rect area\n\
            *\n" );
        
        }
        { //::CEGUI::Rect::getWidth
        
            typedef float ( ::CEGUI::Rect::*getWidth_function_type )(  ) const;
            
            Rect_exposer.def( 
                "getWidth"
                , getWidth_function_type( &::CEGUI::Rect::getWidth )
                , "*!\n\
            \n\
               return width of Rect area\n\
            *\n" );
        
        }
        { //::CEGUI::Rect::isPointInRect
        
            typedef bool ( ::CEGUI::Rect::*isPointInRect_function_type )( ::CEGUI::Vector2 const & ) const;
            
            Rect_exposer.def( 
                "isPointInRect"
                , isPointInRect_function_type( &::CEGUI::Rect::isPointInRect )
                , ( bp::arg("pt") )
                , "*!\n\
               \n\
                  Return true if the given Point falls within this Rect\n\
            \n\
               @param pt\n\
                  Point object describing the position to test.\n\
            \n\
               @return\n\
                  true if position  pt is within this Rect's area, else false\n\
               *\n" );
        
        }
        { //::CEGUI::Rect::offset
        
            typedef ::CEGUI::Rect & ( ::CEGUI::Rect::*offset_function_type )( ::CEGUI::Vector2 const & ) ;
            
            Rect_exposer.def( 
                "offset"
                , offset_function_type( &::CEGUI::Rect::offset )
                , ( bp::arg("pt") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
               \n\
                  Applies an offset the Rect object\n\
            \n\
               @param pt\n\
                  Point object containing the offsets to be applied to the Rect.\n\
            \n\
               @return\n\
                  this Rect after the offset is performed\n\
               *\n" );
        
        }
        Rect_exposer.def( bp::self != bp::self );
        Rect_exposer.def( bp::self * bp::other< float >() );
        Rect_exposer.def( bp::self *= bp::other< float >() );
        Rect_exposer.def( bp::self + bp::self );
        { //::CEGUI::Rect::operator=
        
            typedef ::CEGUI::Rect & ( ::CEGUI::Rect::*assign_function_type )( ::CEGUI::Rect const & ) ;
            
            Rect_exposer.def( 
                "assign"
                , assign_function_type( &::CEGUI::Rect::operator= )
                , ( bp::arg("rhs") )
                , bp::return_self< >() );
        
        }
        Rect_exposer.def( bp::self == bp::self );
        { //::CEGUI::Rect::setHeight
        
            typedef void ( ::CEGUI::Rect::*setHeight_function_type )( float ) ;
            
            Rect_exposer.def( 
                "setHeight"
                , setHeight_function_type( &::CEGUI::Rect::setHeight )
                , ( bp::arg("height") )
                , "*!\n\
            \n\
               set the height of the Rect object\n\
            *\n" );
        
        }
        { //::CEGUI::Rect::setPosition
        
            typedef void ( ::CEGUI::Rect::*setPosition_function_type )( ::CEGUI::Vector2 const & ) ;
            
            Rect_exposer.def( 
                "setPosition"
                , setPosition_function_type( &::CEGUI::Rect::setPosition )
                , ( bp::arg("pt") )
                , "*!\n\
            \n\
               set the position of the Rect (leaves size in tact)\n\
            *\n" );
        
        }
        { //::CEGUI::Rect::setSize
        
            typedef void ( ::CEGUI::Rect::*setSize_function_type )( ::CEGUI::Size const & ) ;
            
            Rect_exposer.def( 
                "setSize"
                , setSize_function_type( &::CEGUI::Rect::setSize )
                , ( bp::arg("sze") )
                , "*!\n\
            \n\
               set the size of the Rect area\n\
            *\n" );
        
        }
        { //::CEGUI::Rect::setWidth
        
            typedef void ( ::CEGUI::Rect::*setWidth_function_type )( float ) ;
            
            Rect_exposer.def( 
                "setWidth"
                , setWidth_function_type( &::CEGUI::Rect::setWidth )
                , ( bp::arg("width") )
                , "*!\n\
            \n\
               set the width of the Rect object\n\
            *\n" );
        
        }
        Rect_exposer.def_readwrite( "d_bottom", &CEGUI::Rect::d_bottom, "*************************************************************************\n\
           Data Fields\n\
        *************************************************************************\n" );
        Rect_exposer.def_readwrite( "d_left", &CEGUI::Rect::d_left, "*************************************************************************\n\
           Data Fields\n\
        *************************************************************************\n" );
        Rect_exposer.def_readwrite( "d_right", &CEGUI::Rect::d_right, "*************************************************************************\n\
           Data Fields\n\
        *************************************************************************\n" );
        Rect_exposer.def_readwrite( "d_top", &CEGUI::Rect::d_top, "*************************************************************************\n\
           Data Fields\n\
        *************************************************************************\n" );
    }

}