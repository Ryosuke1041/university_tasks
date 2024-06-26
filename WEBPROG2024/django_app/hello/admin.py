from django.contrib import admin

from import_export import resources
from import_export.admin import ImportExportModelAdmin
from .models import Friend, Message
# Register your models here.
class FriendResource(resources.ModelResource):
    # Modelに対するdjango-import-exportの設定
    class Meta:
        model = Friend

class MessageResource(resources.ModelResource):
    class Meta:
        model = Message

@admin.register(Friend)
class HelloAdmin(ImportExportModelAdmin):
    # ImportExportModelAdminを利用するようにする
    ordering = ['id']
    list_display = ('id', 'name', 'mail', 'gender', 'age', 'birthday')
    # django-import-exportsの設定
    resource_class = FriendResource

@admin.register(Message)    
class MessageAdmin(ImportExportModelAdmin):
    # ImportExportModelAdminを利用するようにする
    ordering = ['id']
    list_display = ('id', 'friend', 'title', 'content', 'pub_date')
    # django-import-exportsの設定
    resource_class = MessageResource