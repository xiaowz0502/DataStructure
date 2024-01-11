// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;


// Add your test cases here

TEST(test_1) {
    List<int> my_list;
    
    ASSERT_TRUE(my_list.empty());
    ASSERT_TRUE(my_list.size() == 0);

    my_list.push_front(1);
    my_list.push_back(2);
    
    ASSERT_TRUE(my_list.front() == 1);
    ASSERT_TRUE(my_list.back() == 2);

    ASSERT_TRUE(my_list.size() == 2);
    
    my_list.pop_front();
    ASSERT_TRUE(my_list.size() == 1);
    my_list.pop_back();
    ASSERT_TRUE(my_list.size() == 0);
    
}

TEST(test_push_pop_clear_empty) {
    // Add test code here
    List<int> i;
    assert(i.empty());
    
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    
    i.pop_front();
    assert(i.front() == 6);
    i.pop_back();
    assert(i.back() == 4);
    i.clear();
    assert(i.empty());
    i.~List();
}

TEST(List_copy_test_default){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    List<int> m (i);
    
    assert(m.size() == i.size());
    List<int>::Iterator b = i.begin();
    for (List<int>::Iterator a = m.begin();
         a != m.end(); ++a,++b){
        assert (*a == *b);
    }
}

TEST(List_copy_test_operator){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    List<int> m = i;
    
    assert(m.size() == i.size());
    List<int>::Iterator b = i.begin();
    for (List<int>::Iterator a = m.begin();
         a != m.end(); ++a){
        assert (*a == *b);  //reverse order
        ++b;
    }
}



TEST(Iterator_plus_minus){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    
    List<int>::Iterator a = i.begin();
    assert(*a == 7);
    ++a;
    assert(*a == 6);
    ++a;
    assert(*a == 5);
    --a;
    assert(*a == 6);
}

TEST(Iterator_equal_notequal){
    
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    List<int>::Iterator a = i.begin();
    
    List<int>::Iterator b = ++i.begin();
    assert(*a != *b);
    
    i.clear();
    assert(i.empty());
    
    i.push_front(5);
    i.push_front(5);
    a = i.begin();
    b = ++i.begin();
    assert(*a == *b);
    
}

TEST(erase_test){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    assert(i.size() == 5);
    List<int>::Iterator a = i.begin();//7
    ++a;//6
    ++a;//5
    i.erase(a);
    assert(i.size() == 4);
    List<int>::Iterator b = i.begin();
    assert(*b == 7);
    ++b;
    assert(*b == 6);
    ++b;
    assert(*b == 4);
    ++b;
    assert(*b == 3);
}

TEST(erase_test2){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    List<int>::Iterator a = i.begin();//5
    i.erase(a);
    assert(i.size()==0);
    assert(i.empty());
    
    i.push_front(5);
    i.push_back(6);
    List<int>::Iterator b = i.begin();//5
    ++b;
    i.erase(b);
    List<int>::Iterator c = i.begin();
    assert(*c == 5);
}

TEST(erase_test3){
    List<int> i;
    i.push_front(5);
    i.push_back(6);
    List<int>::Iterator b = i.begin();
    i.erase(b);
    List<int>::Iterator c = i.begin();
    assert(*c == 6);
}

TEST(erase_test4){
    List<int> i;
    i.push_front(5);
    i.push_back(6);
    List<int>::Iterator b = i.begin();
    ++b;
    i.erase(b);
    List<int>::Iterator c = i.begin();
    assert(*c == 5);
    assert(i.size()==1);
}

TEST(insert_test){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    List<int>::Iterator a = i.begin();//7
    i.insert(a, 8);
    assert(i.front() == 8);
    a = i.begin();
    ++a;
    assert(*a == 7);
    ++a;
    assert(*a == 6);
}

TEST(insert_test2){
        List<int> i;
        assert(i.empty());
        i.push_front(5);
        i.push_front(6);
        i.push_front(7); //{7,6,5}
        i.push_back(4);
        i.push_back(3); //{7.6.5.4.3}
        List<int>::Iterator a = i.begin();
        ++a;
        --a;
        assert(*a == 7);
        ++a;
        ++a; //5
        i.insert(a,1);
}


TEST(insert_test3){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    
    assert(i.size() == 5);
    List<int>::Iterator a = i.begin();
    ++a;
    --a;
    assert(*a == 7);
    ++a;
    ++a; //5
    i.insert(a,1);
    --a;
    assert(*a == 1);
    assert(i.size() == 6);
}

TEST(insert_test4){
    List<int> i;
    assert(i.empty());
    i.push_front(5);
    i.push_front(6);
    i.push_front(7); //{7,6,5}
    i.push_back(4);
    i.push_back(3); //{7.6.5.4.3}
    
    assert(i.size() == 5);
    List<int>::Iterator a = i.end();
    i.insert(a,1);
    
    List<int>::Iterator b = i.begin();
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    assert(*b == 1);
    assert(i.size() == 6);
}

TEST_MAIN()

