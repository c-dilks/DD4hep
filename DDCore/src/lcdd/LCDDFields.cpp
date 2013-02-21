// $Id:$
//====================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------
//
//  Author     : M.Frank
//
//====================================================================

// Framework includes
#include "DD4hep/FieldTypes.h"
#include "DD4hep/DetFactoryHelper.h"

using namespace DD4hep::Geometry;

static Ref_t convert_constant_field(LCDD& lcdd, xml_h field, Ref_t object) {
  xml_doc_t doc = xml_elt_t(field).document();
  ConstantField* s = object.data<ConstantField>();
  field.setAttr(_A(lunit),"mm");
  //field.setAttr(_A(funit),"tesla");
  if ( s->type == CartesianField::ELECTRIC )
    field.setAttr(_A(field),"electric");
  else if ( s->type == CartesianField::MAGNETIC )
    field.setAttr(_A(field),"magnetic");

  xml_elt_t strength = xml_elt_t(doc,_X(strength));
  strength.setAttr(_A(x),s->direction.X());
  strength.setAttr(_A(y),s->direction.Y());
  strength.setAttr(_A(z),s->direction.Z());
  field.append(strength);
  return object;
}
DECLARE_XML_PROCESSOR(ConstantField_Convert2LCDD,convert_constant_field);

static Ref_t convert_solenoid(LCDD& lcdd, xml_h field, Ref_t object) {
  char text[128];
  SolenoidField* s = object.data<SolenoidField>();
  field.setAttr(_A(lunit),"mm");
  field.setAttr(_A(funit),"tesla");
  ::sprintf(text,"%g/mm",s->outerRadius);
  field.setAttr(_A(outer_radius),_toDouble(text));
  ::sprintf(text,"%g/mm",s->innerRadius);
  field.setAttr(_A(inner_radius),_toDouble(text));
  ::sprintf(text,"%g/tesla",s->innerField);
  field.setAttr(_A(inner_field),_toDouble(text));
  ::sprintf(text,"%g/tesla",s->outerField);
  field.setAttr(_A(outer_field),_toDouble(text));
  field.setAttr(_A(zmin),s->minZ);
  field.setAttr(_A(zmax),s->maxZ);
  return object;
}
DECLARE_XML_PROCESSOR(SolenoidMagnet_Convert2LCDD,convert_solenoid);

static Ref_t convert_dipole(LCDD& lcdd, xml_h field, Ref_t object) {
  char text[128];
  xml_doc_t doc = xml_elt_t(field).document();
  DipoleField* s = object.data<DipoleField>();
  field.setAttr(_A(lunit),"mm");
  field.setAttr(_A(funit),"tesla");
  ::sprintf(text,"%g/mm",s->rmax);
  field.setAttr(_A(rmax),_toDouble(text));
  ::sprintf(text,"%g/mm",s->zmax);
  field.setAttr(_A(zmax),_toDouble(text));
  ::sprintf(text,"%g/mm",s->zmin);
  field.setAttr(_A(zmin),_toDouble(text));
  DipoleField::Coefficents::const_iterator i=s->coefficents.begin();
  for(; i != s->coefficents.end(); ++i) {
    xml_elt_t coeff = xml_elt_t(doc,_X(dipole_coeff));
    coeff.setValue(_toString(*i));
    field.append(coeff);
  }
  return object;
}
DECLARE_XML_PROCESSOR(DipoleField_Convert2LCDD,convert_dipole);

