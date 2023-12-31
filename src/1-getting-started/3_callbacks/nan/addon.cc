#include <nan.h>

void RunCallback(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Function> cb = info[0].As<v8::Function>();
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = {Nan::New("hello world").ToLocalChecked()};
  Nan::AsyncResource resource("nan:makeCallback");
  resource.runInAsyncScope(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Module> module){
    Nan::SetMethod(module, "exports", RunCallback)} NODE_MODULE(addon, Init)