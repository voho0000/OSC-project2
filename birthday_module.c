#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>

struct birthday {
    int day;
    int month;
    int year;
    struct list_head list;
};

static LIST_HEAD(birthday_list);

static int __init birthday_init(void) {
    struct birthday *person;
    int i;

    printk(KERN_INFO "Loading birthday module\n");

    for (i = 0; i < 5; i++) {
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        person->day = i + 1;
        person->month = i + 1;
        person->year = 2000 + i;

        INIT_LIST_HEAD(&person->list);
        list_add_tail(&person->list, &birthday_list);
    }

    list_for_each_entry(person, &birthday_list, list) {
        printk(KERN_INFO "Birthday: Day %d Month %d Year %d\n", person->day, person->month, person->year);
    }

    return 0;
}

static void __exit birthday_exit(void) {
    struct birthday *person, *next;

    printk(KERN_INFO "Removing birthday module\n");

    list_for_each_entry_safe(person, next, &birthday_list, list) {
        printk(KERN_INFO "Removing Birthday: Day %d Month %d Year %d\n", person->day, person->month, person->year);
        list_del(&person->list);
        kfree(person);
    }
}

module_init(birthday_init);
module_exit(birthday_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yi-Hsin");
MODULE_DESCRIPTION("A kernel module to manage a list of birthdays");
MODULE_VERSION("0.1");

