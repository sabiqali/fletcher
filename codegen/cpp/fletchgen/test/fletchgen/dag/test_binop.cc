// Copyright 2018-2019 Delft University of Technology
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>
#include <vector>

#include "fletchgen/dag/test_utils.h"
#include "fletchgen/dag/api.h"

namespace fletchgen::dag {

TEST(BinOps, Prim) {

  auto g = Graph();

  auto a = g <<= Source("a", u32());
  auto split_a = g <<= Duplicate(u32(), 4);
  g <<= split_a << a;
  auto b = g <<= Source("b", u32());
  auto split_b = g <<= Duplicate(u32(), 4);
  g <<= split_b << b;

  auto q = g <<= Sink("q", u32());
  auto r = g <<= Sink("r", u32());
  auto s = g <<= Sink("s", u32());
  auto t = g <<= Sink("t", u32());

  auto add = g <<= BinOp(u32(), "+", u32());
  g <<= add(0) << split_a.o(0);
  g <<= add(1) << split_b.o(0);
  g <<= q << add;

  auto sub = g <<= BinOp(u32(), "-", u32());
  g <<= sub(0) << split_a.o(1);
  g <<= sub(1) << split_b.o(1);
  g <<= r << sub;

  auto mul = g <<= BinOp(u32(), "*", u32());
  g <<= mul(0) << split_a.o(2);
  g <<= mul(1) << split_b.o(2);
  g <<= s << mul;

  auto div = g <<= BinOp(u32(), "/", u32());
  g <<= div(0) << split_a.o(3);
  g <<= div(1) << split_b.o(3);
  g <<= t << div;

  DumpToDot(g);
}

TEST(BinOps, ListPrim) {

  auto g = Graph();
  auto lu32 = list(u32());
  auto a = g <<= Source("a", lu32);
  auto split_a = g <<= Duplicate(lu32, 4);
  g <<= split_a << a;
  auto b = g <<= Source("b", u32());
  auto split_b = g <<= Duplicate(u32(), 4);
  g <<= split_b << b;

  auto q = g <<= Sink("q", lu32);
  auto r = g <<= Sink("r", lu32);
  auto s = g <<= Sink("s", lu32);
  auto t = g <<= Sink("t", lu32);

  auto add = g <<= BinOp(lu32, "+", u32());
  g <<= add(0) << split_a.o(0);
  g <<= add(1) << split_b.o(0);
  g <<= q << add;

  auto sub = g <<= BinOp(lu32, "-", u32());
  g <<= sub(0) << split_a.o(1);
  g <<= sub(1) << split_b.o(1);
  g <<= r << sub;

  auto mul = g <<= BinOp(lu32, "*", u32());
  g <<= mul(0) << split_a.o(2);
  g <<= mul(1) << split_b.o(2);
  g <<= s << mul;

  auto div = g <<= BinOp(lu32, "/", u32());
  g <<= div(0) << split_a.o(3);
  g <<= div(1) << split_b.o(3);
  g <<= t << div;

  DumpToDot(g);
}

TEST(BinOps, ListList) {

  auto g = Graph();
  auto lu32 = list(u32());
  auto a = g <<= Source("a", lu32);
  auto split_a = g <<= Duplicate(lu32, 4);
  g <<= split_a << a;
  auto b = g <<= Source("b", lu32);
  auto split_b = g <<= Duplicate(lu32, 4);
  g <<= split_b << b;

  auto q = g <<= Sink("q", lu32);
  auto r = g <<= Sink("r", lu32);
  auto s = g <<= Sink("s", lu32);
  auto t = g <<= Sink("t", lu32);

  auto add = g <<= BinOp(lu32, "+", lu32);
  g <<= add(0) << split_a.o(0);
  g <<= add(1) << split_b.o(0);
  g <<= q << add;

  auto sub = g <<= BinOp(lu32, "-", lu32);
  g <<= sub(0) << split_a.o(1);
  g <<= sub(1) << split_b.o(1);
  g <<= r << sub;

  auto mul = g <<= BinOp(lu32, "*", lu32);
  g <<= mul(0) << split_a.o(2);
  g <<= mul(1) << split_b.o(2);
  g <<= s << mul;

  auto div = g <<= BinOp(lu32, "/", lu32);
  g <<= div(0) << split_a.o(3);
  g <<= div(1) << split_b.o(3);
  g <<= t << div;

  DumpToDot(g);
}

TEST(BinOps, StructPrim) {

  auto lu32 = list(u32());
  auto su32 = struct_({field("f0", lu32), field("f1", lu32)});

  auto g = Graph();

  auto a = g <<= Source("a", su32);
  auto split_a = g <<= Duplicate(su32, 4);
  g <<= split_a << a;
  auto b = g <<= Source("b", u32());
  auto split_b = g <<= Duplicate(u32(), 4);
  g <<= split_b << b;

  auto q = g <<= Sink("q", su32);
  auto r = g <<= Sink("r", su32);
  auto s = g <<= Sink("s", su32);
  auto t = g <<= Sink("t", su32);

  auto add = g <<= BinOp(su32, "+", u32());
  g <<= add(0) << split_a.o(0);
  g <<= add(1) << split_b.o(0);
  g <<= q << add;

  auto sub = g <<= BinOp(su32, "-", u32());
  g <<= sub(0) << split_a.o(1);
  g <<= sub(1) << split_b.o(1);
  g <<= r << sub;

  auto mul = g <<= BinOp(su32, "*", u32());
  g <<= mul(0) << split_a.o(2);
  g <<= mul(1) << split_b.o(2);
  g <<= s << mul;

  auto div = g <<= BinOp(su32, "/", u32());
  g <<= div(0) << split_a.o(3);
  g <<= div(1) << split_b.o(3);
  g <<= t << div;

  DumpToDot(g);
}

TEST(BinOps, StructList) {

  auto lu32 = list(u32());
  auto su32 = struct_({field("f0", lu32), field("f1", lu32)});

  auto g = Graph();

  auto a = g <<= Source("a", su32);
  auto split_a = g <<= Duplicate(su32, 4);
  g <<= split_a << a;
  auto b = g <<= Source("b", lu32);
  auto split_b = g <<= Duplicate(lu32, 4);
  g <<= split_b << b;

  auto q = g <<= Sink("q", su32);
  auto r = g <<= Sink("r", su32);
  auto s = g <<= Sink("s", su32);
  auto t = g <<= Sink("t", su32);

  auto add = g <<= BinOp(su32, "+", lu32);
  g <<= add(0) << split_a.o(0);
  g <<= add(1) << split_b.o(0);
  g <<= q << add;

  auto sub = g <<= BinOp(su32, "-", lu32);
  g <<= sub(0) << split_a.o(1);
  g <<= sub(1) << split_b.o(1);
  g <<= r << sub;

  auto mul = g <<= BinOp(su32, "*", lu32);
  g <<= mul(0) << split_a.o(2);
  g <<= mul(1) << split_b.o(2);
  g <<= s << mul;

  auto div = g <<= BinOp(su32, "/", lu32);
  g <<= div(0) << split_a.o(3);
  g <<= div(1) << split_b.o(3);
  g <<= t << div;

  DumpToDot(g);
}

TEST(BinOps, StructStruct) {

  auto lu32 = list(u32());
  auto su32 = struct_({field("f0", lu32), field("f1", lu32)});

  auto g = Graph();

  auto a = g <<= Source("a", su32);
  auto split_a = g <<= Duplicate(su32, 4);
  g <<= split_a << a;
  auto b = g <<= Source("b", su32);
  auto split_b = g <<= Duplicate(su32, 4);
  g <<= split_b << b;

  auto q = g <<= Sink("q", su32);
  auto r = g <<= Sink("r", su32);
  auto s = g <<= Sink("s", su32);
  auto t = g <<= Sink("t", su32);

  auto add = g <<= BinOp(su32, "+", su32);
  g <<= add(0) << split_a.o(0);
  g <<= add(1) << split_b.o(0);
  g <<= q << add;

  auto sub = g <<= BinOp(su32, "-", su32);
  g <<= sub(0) << split_a.o(1);
  g <<= sub(1) << split_b.o(1);
  g <<= r << sub;

  auto mul = g <<= BinOp(su32, "*", su32);
  g <<= mul(0) << split_a.o(2);
  g <<= mul(1) << split_b.o(2);
  g <<= s << mul;

  auto div = g <<= BinOp(su32, "/", su32);
  g <<= div(0) << split_a.o(3);
  g <<= div(1) << split_b.o(3);
  g <<= t << div;

  DumpToDot(g);
}

}  // namespace fletchgen::dag
