<template>
  <div class="container">
    <div class="form">
      <input
        v-model="sourcePath"
        type="text"
        placeholder="Source directory path"
        class="input"
      />
      <input
        v-model="destinationPath"
        type="text"
        placeholder="Destination directory path"
        class="input"
      />
      <button class="copy-btn" @click="copyFiles">Copy</button>
    </div>
  </div>
</template>

<script>
export default {
  name: "BackupManager",
  data() {
    return {
      sourcePath: "",
      destinationPath: "",
    };
  },
  methods: {
    copyFiles() {
      // For now, just log to simulate action
      console.log(
        `Copying from ${this.sourcePath} to ${this.destinationPath}`
      );
      // Here you’d call your backend to perform the copy operation
    },
  },
};
</script>

<style scoped>
.container {
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100vh;
  background-color: rgb(255, 0, 255);
}

.form {
  display: flex;
  flex-direction: column;
  gap: 1rem;
  text-align: center;
}

.input {
  padding: 0.75rem;
  border-radius: 8px;
  border: none;
  width: 300px;
}

.copy-btn {
  padding: 0.75rem;
  border: none;
  border-radius: 8px;
  background-color: green;
  color: white;
  font-weight: bold;
  cursor: pointer;
}

.copy-btn:hover {
  background-color: darkgreen;
}
</style>
