#include <gtest/gtest.h>
#include "../src/HashFuncConfirm.cpp"
#include <string>
#include <vector>

using namespace std;

TEST(addItemHashFunctionConfirm, addingItem) {
    FalsePositive hey;
    hey.addItemToSet("Hello world");
    string i = *hey.getItemsSet().find("Hello world");
    ASSERT_EQ(i, "Hello world");
    }

TEST(ItemIsIn, check1) {
    FalsePositive hey;
    hey.addItemToSet("Hello world");
    hey.addItemToSet("skdja;skj d231037 81asdasnd 208 1sjdnladnslg390hr1ornld;nsdfh q39py139shhsfkljslknxb,.v.d askdj ah aufq");
    hey.addItemToSet("#Q*&B UOYVA)(^#Q)B(&#@Q RQOBFKBZLB()#Y)Q()(#&%^&DASIUF D)");
    ASSERT_EQ(hey.ItemIsIn("Hello world"), true);
    ASSERT_EQ(hey.ItemIsIn("heyyy world"), false);
    ASSERT_EQ(hey.ItemIsIn("skdja;skj d231037 81asdasnd 208 1sjdnladnslg390hr1ornld;nsdfh q39py139shhsfkljslknxb,.v.d askdj ah aufq"), true);
    ASSERT_EQ(hey.ItemIsIn("#Q*&B UOYVA)(^#Q)B(&#@Q RQOBFKBZLB()#Y)Q()(#&%^&DASIUF D)"), true);
 }