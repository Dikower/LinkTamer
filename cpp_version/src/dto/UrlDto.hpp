#ifndef UrlDto_hpp
#define UrlDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class UrlDto : public oatpp::DTO {

  DTO_INIT(UrlDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(String, url, "url");
  DTO_FIELD(String, shorten, "shorten");
  DTO_FIELD(Int32 , use_amount, "use_amount") = 0;
};

#include OATPP_CODEGEN_END(DTO)

#endif /* UrlDto_hpp */
