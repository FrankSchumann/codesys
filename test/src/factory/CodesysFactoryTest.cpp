#include <gtest/gtest.h>

#include "copa-pdk/mock/component/ComponentController.h"
#include "factory/CodesysFactory.h"
#include "runtime-sdk/mock/RuntimeController.h"

TEST( CodesysFactoryTest, Failed )
{
	GTEST_FAIL();
}

TEST( CodesysFactoryTest, create )
{
    auto componentController = std::make_shared< Mock::ComponentController >();
    auto runtimeController = std::make_shared< Mock::RuntimeController >();

    EXPECT_CALL( *componentController, get( testing::_, testing::_ ) ).WillOnce( testing::Return( runtimeController ) );
    EXPECT_CALL( *runtimeController, subscribe( testing::_, testing::_ ) ).Times( testing::Exactly( 1 ) );

    CodesysFactory codesysFactory = CodesysFactory( componentController );

    std::string const name = std::string( "Daisy Duck" );
    auto codesys = codesysFactory.create( name );

    ASSERT_NE( nullptr, codesys );

    ASSERT_EQ( name, codesys->getName() );
    ASSERT_EQ( std::string( "CodesysAdapter" ), codesys->getType() );
}

TEST( CodesysFactoryTest, getType )
{
    CodesysFactory codesysFactory;

    std::string const type = codesysFactory.getType();

    EXPECT_EQ( "CodesysAdapter", type );
}
