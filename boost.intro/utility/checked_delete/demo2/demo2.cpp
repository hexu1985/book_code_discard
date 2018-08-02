// Test application
#include "deleter.h"
#include "to_be_deleted.h"

int main() {
  to_be_deleted* p=new to_be_deleted;

  deleter d;
  d.delete_it(p);
}

