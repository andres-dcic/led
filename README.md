#demo githubactions esp32

# GitHub Actions para Integración Continua

GitHub Actions es una plataforma de integración continua y entrega continua (CI/CD) que permite automatizar flujos de trabajo directamente en tu repositorio de GitHub. Puedes usar GitHub Actions para construir, probar y desplegar tu código cada vez que se realiza un cambio en el repositorio.

## Conceptos Clave

1. **Flujos de Trabajo (Workflows)**
   - Son procesos automatizados definidos en archivos YAML dentro del directorio `.github/workflows` de tu repositorio.
   - Los flujos de trabajo se pueden activar por diferentes eventos, como push, pull request, o en un horario específico.

2. **Jobs**
   - Un flujo de trabajo puede estar compuesto por uno o más jobs.
   - Los jobs se ejecutan en entornos de ejecución (runners) y pueden ejecutarse en paralelo o secuencialmente, dependiendo de la configuración.

3. **Steps**
   - Cada job se compone de steps (pasos), que son comandos o acciones individuales a ejecutar dentro del job.
   - Los steps pueden incluir comandos shell, scripts personalizados o acciones reutilizables.

4. **Actions**
   - Las acciones son unidades reutilizables de código que pueden ser combinadas en tus workflows.
   - Puedes utilizar acciones predefinidas desde el GitHub Marketplace o escribir tus propias acciones personalizadas.

5. **Runners**
   - Los runners son servidores que ejecutan tus jobs.
   - GitHub proporciona runners hospedados en la nube, o puedes utilizar runners auto-hospedados en tu propia infraestructura.

## Ejemplo de Flujo de Trabajo para Integración Continua

A continuación, un ejemplo de archivo YAML para un flujo de trabajo de integración continua que construye y prueba un proyecto Node.js:

```yaml
name: Integracion Continua

on:
  push:
    branches:
      - main
  #pull_request:
  # branches:
  #  - main

jobs:
  build:
    runs-on: ubuntu-latest
    
    steps:
    - name: Echo message
      run: |
        echo "Hola Ingenieros"
```


