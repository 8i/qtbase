/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtTest/QtTest>
#include <QtCore/qtypetraits.h>

class tst_QGlobal: public QObject
{
    Q_OBJECT

private slots:
    void qIsNull();
    void for_each();
    void qassert();
    void qtry();
    void checkptr();
    void qstaticassert();
    void qConstructorFunction();
    void isEnum();
    void qAlignOf();
};

void tst_QGlobal::qIsNull()
{
    double d = 0.0;
    float f = 0.0f;

    QVERIFY(::qIsNull(d));
    QVERIFY(::qIsNull(f));

    d += 0.000000001;
    f += 0.0000001f;

    QVERIFY(!::qIsNull(d));
    QVERIFY(!::qIsNull(f));

    d = -0.0;
    f = -0.0f;

    QVERIFY(::qIsNull(d));
    QVERIFY(::qIsNull(f));
}

void tst_QGlobal::for_each()
{
    QList<int> list;
    list << 0 << 1 << 2 << 3 << 4 << 5;

    int counter = 0;
    foreach(int i, list) {
        QCOMPARE(i, counter++);
    }
    QCOMPARE(counter, list.count());

    // do it again, to make sure we don't have any for-scoping
    // problems with older compilers
    counter = 0;
    foreach(int i, list) {
        QCOMPARE(i, counter++);
    }
    QCOMPARE(counter, list.count());
}

void tst_QGlobal::qassert()
{
    bool passed = false;
    if (false) {
        Q_ASSERT(false);
    } else {
        passed = true;
    }
    QVERIFY(passed);

    passed = false;
    if (false) {
        Q_ASSERT_X(false, "tst_QGlobal", "qassert");
    } else {
        passed = true;
    }
    QVERIFY(passed);

    passed = false;
    if (false)
        Q_ASSERT(false);
    else
        passed = true;
    QVERIFY(passed);

    passed = false;
    if (false)
        Q_ASSERT_X(false, "tst_QGlobal", "qassert");
    else
        passed = true;
    QVERIFY(passed);
}

void tst_QGlobal::qtry()
{
    int i = 0;
    QT_TRY {
        i = 1;
        QT_THROW(42);
        i = 2;
    } QT_CATCH(int) {
        QCOMPARE(i, 1);
        i = 7;
    }
#ifdef QT_NO_EXCEPTIONS
    QCOMPARE(i, 2);
#else
    QCOMPARE(i, 7);
#endif

    // check propper if/else scoping
    i = 0;
    if (true) {
        QT_TRY {
            i = 2;
            QT_THROW(42);
            i = 4;
        } QT_CATCH(int) {
            QCOMPARE(i, 2);
            i = 4;
        }
    } else {
        QCOMPARE(i, 0);
    }
    QCOMPARE(i, 4);

    i = 0;
    if (false) {
        QT_TRY {
            i = 2;
            QT_THROW(42);
            i = 4;
        } QT_CATCH(int) {
            QCOMPARE(i, 2);
            i = 2;
        }
    } else {
        i = 8;
    }
    QCOMPARE(i, 8);

    i = 0;
    if (false) {
        i = 42;
    } else {
        QT_TRY {
            i = 2;
            QT_THROW(42);
            i = 4;
        } QT_CATCH(int) {
            QCOMPARE(i, 2);
            i = 4;
        }
    }
    QCOMPARE(i, 4);
}

void tst_QGlobal::checkptr()
{
    int i;
    QCOMPARE(q_check_ptr(&i), &i);

    const char *c = "hello";
    QCOMPARE(q_check_ptr(c), c);
}

// Check Q_STATIC_ASSERT, It should compile
// note that, we are not able to test Q_STATIC_ASSERT(false), to do it manually someone has
// to replace expressions (in the asserts) one by one to false, and check if it breaks build.
class MyTrue
{
public:
    MyTrue()
    {
        Q_STATIC_ASSERT(true);
        Q_STATIC_ASSERT(!false);
        Q_STATIC_ASSERT_X(true,"");
        Q_STATIC_ASSERT_X(!false,"");
    }
    ~MyTrue()
    {
        Q_STATIC_ASSERT(true);
        Q_STATIC_ASSERT(!false);
        Q_STATIC_ASSERT_X(true,"");
        Q_STATIC_ASSERT_X(!false,"");
    }
    Q_STATIC_ASSERT(true);
    Q_STATIC_ASSERT(!false);
    Q_STATIC_ASSERT_X(true,"");
    Q_STATIC_ASSERT_X(!false,"");
};

struct MyExpresion
{
    void foo()
    {
        Q_STATIC_ASSERT(sizeof(MyTrue) > 0);
        Q_STATIC_ASSERT(sizeof(MyTrue) > 0);
        Q_STATIC_ASSERT_X(sizeof(MyTrue) > 0,"");
        Q_STATIC_ASSERT_X(sizeof(MyTrue) > 0,"");
    }
private:
    Q_STATIC_ASSERT(sizeof(MyTrue) > 0);
    Q_STATIC_ASSERT(sizeof(MyTrue) > 0);
    Q_STATIC_ASSERT_X(sizeof(MyTrue) > 0, "");
    Q_STATIC_ASSERT_X(sizeof(MyTrue) > 0, "");
};

struct TypeDef
{
    typedef int T;
    Q_STATIC_ASSERT(sizeof(T));
    Q_STATIC_ASSERT_X(sizeof(T), "");
};

template<typename T1, typename T2>
struct Template
{
    static const bool True = true;
    typedef typename T1::T DependentType;
    Q_STATIC_ASSERT(True);
    Q_STATIC_ASSERT(!!True);
    Q_STATIC_ASSERT(sizeof(DependentType));
    Q_STATIC_ASSERT(!!sizeof(DependentType));
    Q_STATIC_ASSERT_X(True, "");
    Q_STATIC_ASSERT_X(!!True, "");
    Q_STATIC_ASSERT_X(sizeof(DependentType), "");
    Q_STATIC_ASSERT_X(!!sizeof(DependentType), "");
};

struct MyTemplate
{
    static const bool Value = Template<TypeDef, int>::True;
    Q_STATIC_ASSERT(Value);
    Q_STATIC_ASSERT(!!Value);
    Q_STATIC_ASSERT_X(Value, "");
    Q_STATIC_ASSERT_X(!!Value, "");
};

void tst_QGlobal::qstaticassert()
{
    // Force compilation of these classes
    MyTrue tmp1;
    MyExpresion tmp2;
    MyTemplate tmp3;
    Q_UNUSED(tmp1);
    Q_UNUSED(tmp2);
    Q_UNUSED(tmp3);
    QVERIFY(true); // if the test compiles it has passed.
}

static int qConstructorFunctionValue;
static void qConstructorFunctionCtor()
{
    qConstructorFunctionValue = 123;
}
Q_CONSTRUCTOR_FUNCTION(qConstructorFunctionCtor);

void tst_QGlobal::qConstructorFunction()
{
    QCOMPARE(qConstructorFunctionValue, 123);
}

struct isEnum_A {
    int n_;
};

enum isEnum_B_Byte { isEnum_B_Byte_x = 63 };
enum isEnum_B_Short { isEnum_B_Short_x = 1024 };
enum isEnum_B_Int { isEnum_B_Int_x = 1 << 20 };

union isEnum_C {};

class isEnum_D {
public:
    operator int() const;
};

class isEnum_E {
private:
    operator int() const;
};

class isEnum_F {
public:
    enum AnEnum {};
};

#if defined (Q_COMPILER_CLASS_ENUM)
enum class isEnum_G : qint64 {};
#endif

void tst_QGlobal::isEnum()
{
#if defined (Q_CC_MSVC)
#define IS_ENUM_TRUE(x)     (Q_IS_ENUM(x) == true)
#define IS_ENUM_FALSE(x)    (Q_IS_ENUM(x) == false)
#else
#define IS_ENUM_TRUE(x)     (Q_IS_ENUM(x) == true && QtPrivate::is_enum<x>::value == true)
#define IS_ENUM_FALSE(x)    (Q_IS_ENUM(x) == false && QtPrivate::is_enum<x>::value == false)
#endif

    QVERIFY(IS_ENUM_TRUE(isEnum_B_Byte));
    QVERIFY(IS_ENUM_TRUE(const isEnum_B_Byte));
    QVERIFY(IS_ENUM_TRUE(volatile isEnum_B_Byte));
    QVERIFY(IS_ENUM_TRUE(const volatile isEnum_B_Byte));

    QVERIFY(IS_ENUM_TRUE(isEnum_B_Short));
    QVERIFY(IS_ENUM_TRUE(const isEnum_B_Short));
    QVERIFY(IS_ENUM_TRUE(volatile isEnum_B_Short));
    QVERIFY(IS_ENUM_TRUE(const volatile isEnum_B_Short));

    QVERIFY(IS_ENUM_TRUE(isEnum_B_Int));
    QVERIFY(IS_ENUM_TRUE(const isEnum_B_Int));
    QVERIFY(IS_ENUM_TRUE(volatile isEnum_B_Int));
    QVERIFY(IS_ENUM_TRUE(const volatile isEnum_B_Int));

    QVERIFY(IS_ENUM_TRUE(isEnum_F::AnEnum));
    QVERIFY(IS_ENUM_TRUE(const isEnum_F::AnEnum));
    QVERIFY(IS_ENUM_TRUE(volatile isEnum_F::AnEnum));
    QVERIFY(IS_ENUM_TRUE(const volatile isEnum_F::AnEnum));

    QVERIFY(IS_ENUM_FALSE(void));
    QVERIFY(IS_ENUM_FALSE(isEnum_B_Byte &));
    QVERIFY(IS_ENUM_FALSE(isEnum_B_Byte[1]));
    QVERIFY(IS_ENUM_FALSE(const isEnum_B_Byte[1]));
    QVERIFY(IS_ENUM_FALSE(isEnum_B_Byte[]));
    QVERIFY(IS_ENUM_FALSE(int));
    QVERIFY(IS_ENUM_FALSE(float));
    QVERIFY(IS_ENUM_FALSE(isEnum_A));
    QVERIFY(IS_ENUM_FALSE(isEnum_A *));
    QVERIFY(IS_ENUM_FALSE(const isEnum_A));
    QVERIFY(IS_ENUM_FALSE(isEnum_C));
    QVERIFY(IS_ENUM_FALSE(isEnum_D));
    QVERIFY(IS_ENUM_FALSE(isEnum_E));
    QVERIFY(IS_ENUM_FALSE(void()));
    QVERIFY(IS_ENUM_FALSE(void(*)()));
    QVERIFY(IS_ENUM_FALSE(int isEnum_A::*));
    QVERIFY(IS_ENUM_FALSE(void (isEnum_A::*)()));

    QVERIFY(IS_ENUM_FALSE(size_t));
    QVERIFY(IS_ENUM_FALSE(bool));
    QVERIFY(IS_ENUM_FALSE(wchar_t));

    QVERIFY(IS_ENUM_FALSE(char));
    QVERIFY(IS_ENUM_FALSE(unsigned char));
    QVERIFY(IS_ENUM_FALSE(short));
    QVERIFY(IS_ENUM_FALSE(unsigned short));
    QVERIFY(IS_ENUM_FALSE(int));
    QVERIFY(IS_ENUM_FALSE(unsigned int));
    QVERIFY(IS_ENUM_FALSE(long));
    QVERIFY(IS_ENUM_FALSE(unsigned long));

    QVERIFY(IS_ENUM_FALSE(qint8));
    QVERIFY(IS_ENUM_FALSE(quint8));
    QVERIFY(IS_ENUM_FALSE(qint16));
    QVERIFY(IS_ENUM_FALSE(quint16));
    QVERIFY(IS_ENUM_FALSE(qint32));
    QVERIFY(IS_ENUM_FALSE(quint32));
    QVERIFY(IS_ENUM_FALSE(qint64));
    QVERIFY(IS_ENUM_FALSE(quint64));

    QVERIFY(IS_ENUM_FALSE(void *));
    QVERIFY(IS_ENUM_FALSE(int *));

#if defined (Q_COMPILER_UNICODE_STRINGS)
    QVERIFY(IS_ENUM_FALSE(char16_t));
    QVERIFY(IS_ENUM_FALSE(char32_t));
#endif

#if defined (Q_COMPILER_CLASS_ENUM)
    // Strongly type class enums are not handled by the
    // fallback type traits implementation. Any compiler
    // supported by Qt that supports C++0x class enums
    // should also support the __is_enum intrinsic.
    QVERIFY(Q_IS_ENUM(isEnum_G) == true);
#endif

#undef IS_ENUM_TRUE
#undef IS_ENUM_FALSE
}

struct Empty {};
template <class T> struct AlignmentInStruct { T dummy; };

typedef int (*fun) ();
typedef int (Empty::*memFun) ();

#define TEST_AlignOf(type, alignment)                                       \
    do {                                                                    \
        TEST_AlignOf_impl(type, alignment);                                 \
                                                                            \
        TEST_AlignOf_impl(type &, alignment);                               \
        TEST_AlignOf_RValueRef(type &&, alignment);                         \
                                                                            \
        TEST_AlignOf_impl(type [5], alignment);                             \
        TEST_AlignOf_impl(type (&) [5], alignment);                         \
                                                                            \
        TEST_AlignOf_impl(AlignmentInStruct<type>, alignment);              \
                                                                            \
        /* Some internal sanity validation, just for fun */                 \
        TEST_AlignOf_impl(AlignmentInStruct<type [5]>, alignment);          \
        TEST_AlignOf_impl(AlignmentInStruct<type &>, Q_ALIGNOF(void *));    \
        TEST_AlignOf_impl(AlignmentInStruct<type (&) [5]>,                  \
                Q_ALIGNOF(void *));                                         \
        TEST_AlignOf_RValueRef(AlignmentInStruct<type &&>,                  \
                Q_ALIGNOF(void *));                                         \
    } while (false)                                                         \
    /**/

#ifdef Q_COMPILER_RVALUE_REFS
#define TEST_AlignOf_RValueRef(type, alignment) \
        TEST_AlignOf_impl(type, alignment)
#else
#define TEST_AlignOf_RValueRef(type, alignment) do {} while (false)
#endif

#define TEST_AlignOf_impl(type, alignment) \
    do { \
        QCOMPARE(Q_ALIGNOF(type), size_t(alignment)); \
        /* Compare to native operator for compilers that support it,
           otherwise...  erm... check consistency! :-) */ \
        QCOMPARE(QT_EMULATED_ALIGNOF(type), Q_ALIGNOF(type)); \
    } while (false)
    /**/

void tst_QGlobal::qAlignOf()
{
    // Built-in types, except 64-bit integers and double
    TEST_AlignOf(char, 1);
    TEST_AlignOf(signed char, 1);
    TEST_AlignOf(unsigned char, 1);
    TEST_AlignOf(qint8, 1);
    TEST_AlignOf(quint8, 1);
    TEST_AlignOf(qint16, 2);
    TEST_AlignOf(quint16, 2);
    TEST_AlignOf(qint32, 4);
    TEST_AlignOf(quint32, 4);
    TEST_AlignOf(void *, sizeof(void *));

    // Depends on platform and compiler, disabling test for now
    // TEST_AlignOf(long double, 16);

    // Empty struct
    TEST_AlignOf(Empty, 1);

    // Function pointers
    TEST_AlignOf(fun, Q_ALIGNOF(void *));
    TEST_AlignOf(memFun, Q_ALIGNOF(void *));


    // 64-bit integers and double
    TEST_AlignOf_impl(qint64, 8);
    TEST_AlignOf_impl(quint64, 8);
    TEST_AlignOf_impl(double, 8);

    TEST_AlignOf_impl(qint64 &, 8);
    TEST_AlignOf_impl(quint64 &, 8);
    TEST_AlignOf_impl(double &, 8);

    TEST_AlignOf_RValueRef(qint64 &&, 8);
    TEST_AlignOf_RValueRef(quint64 &&, 8);
    TEST_AlignOf_RValueRef(double &&, 8);

    // 32-bit x86 ABI idiosyncrasies
#if defined(Q_PROCESSOR_X86_32) && !defined(Q_OS_WIN)
    TEST_AlignOf_impl(AlignmentInStruct<qint64>, 4);
#else
    TEST_AlignOf_impl(AlignmentInStruct<qint64>, 8);
#endif

    TEST_AlignOf_impl(AlignmentInStruct<quint64>, Q_ALIGNOF(AlignmentInStruct<qint64>));
    TEST_AlignOf_impl(AlignmentInStruct<double>, Q_ALIGNOF(AlignmentInStruct<qint64>));

    // 32-bit x86 ABI, Clang disagrees with gcc
#if !defined(Q_PROCESSOR_X86_32) || !defined(Q_CC_CLANG)
    TEST_AlignOf_impl(qint64 [5],       Q_ALIGNOF(qint64));
#else
    TEST_AlignOf_impl(qint64 [5],       Q_ALIGNOF(AlignmentInStruct<qint64>));
#endif

    TEST_AlignOf_impl(qint64 (&) [5],   Q_ALIGNOF(qint64 [5]));
    TEST_AlignOf_impl(quint64 [5],      Q_ALIGNOF(quint64 [5]));
    TEST_AlignOf_impl(quint64 (&) [5],  Q_ALIGNOF(quint64 [5]));
    TEST_AlignOf_impl(double [5],       Q_ALIGNOF(double [5]));
    TEST_AlignOf_impl(double (&) [5],   Q_ALIGNOF(double [5]));
}

#undef TEST_AlignOf
#undef TEST_AlignOf_RValueRef
#undef TEST_AlignOf_impl

QTEST_MAIN(tst_QGlobal)
#include "tst_qglobal.moc"
