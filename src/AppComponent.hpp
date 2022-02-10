#ifdef AppComponent_hpp
#define Appcomponent_hpp

#include "oatpp-1.3.0/oatpp/oatpp/web/server/HttpRouter.hpp"
#include "oatpp-1.3.0/oatpp/oatpp/core/macro/component.hpp"

class AppComponent {
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
        return oatpp::web::servcer::HttpRouter::createShared()
    }());
}

#endif // 
