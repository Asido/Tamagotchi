#ifndef __RESOURCEMGRTEST_H__
#define __RESOURCEMGRTEST_H__

#include <cppunit/extensions/HelperMacros.h>

class ResourceManager;

class ResourceMgrTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(ResourceMgrTest);
    CPPUNIT_TEST(GetHandleTest);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void GetHandleTest();

private:
    ResourceManager *resourceMgr;
};

#endif // __RESOURCEMGRTEST_H__