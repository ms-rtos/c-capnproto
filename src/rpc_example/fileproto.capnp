# Based on the addressbook.capnp example in the capnproto C++ project:
# https://github.com/sandstorm-io/capnproto/blob/6816634a08b08bc8f52b4ee809afb58389f19655/c%2B%2B/samples/addressbook.capnp
#
# Copyright (c) 2013-2014 Sandstorm Development Group, Inc. and contributors
# Licensed under the MIT License:
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

@0x9eb32e19f86ee174;

using C = import "./c.capnp";
$C.fieldgetset;

struct ListFilesRequest {
    hasPath @0 :Bool;
    path @1 :Text;
}

struct ListFilesResponse {
  hasError @0 :Bool;
  files @1 :List(FileInfo);

  struct FileInfo {
    inode @0 :UInt64;
    name @1 :Text;
  }
}


