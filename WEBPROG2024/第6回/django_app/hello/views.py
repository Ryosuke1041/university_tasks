from django.shortcuts import render
from django.http import HttpResponse

def index(request, msg, num):
    return HttpResponse(f'メッセージ: {msg}, num= {num}')