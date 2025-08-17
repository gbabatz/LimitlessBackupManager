const { createApp } = Vue;

createApp({
  data() {
    return {
      message: "Hello from Vue 3!",
      count: 0
    };
  },
  methods: {
    increment() {
      this.count++;
    }
  }
}).mount("#app");
