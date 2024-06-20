from django.contrib import admin

from import_export import resources
from import_export.admin import ImportExportModelAdmin
from .models import Friend
# Register your models here.
class FriendResource(resources.ModelResource):
    # Modelに対するdjango-import-exportの設定
    class Meta:
        model = Friend

@admin.register(Friend)
class HelloAdmin(ImportExportModelAdmin):
    # ImportExportModelAdminを利用するようにする
    ordering = ['id']
    list_display = ('id', 'name', 'mail', 'gender', 'age', 'birthday')
    # django-import-exportsの設定
    resource_class = FriendResource